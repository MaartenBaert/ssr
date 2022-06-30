#!/usr/bin/env bash
# Utility script to patch desktop entries in snap, should only be run in the `override-prime` scriptlet
# 林博仁 © 2018

## Makes debuggers' life easier - Unofficial Bash Strict Mode
## BASHDOC: Shell Builtin Commands - Modifying Shell Behavior - The Set Builtin
set \
    -o errexit \
    -o errtrace \
    -o nounset \
    -o pipefail

## Runtime Dependencies Checking
declare\
    runtime_dependency_checking_result=still-pass\
    required_software

for required_command in \
    basename \
    dirname \
    find \
    realpath \
    sed \
    xargs; do
    if ! command -v "${required_command}" &>/dev/null; then
        runtime_dependency_checking_result=fail

        case "${required_command}" in
            basename \
            |dirname \
            |realpath)
                required_software='GNU Coreutils'
                ;;
            find \
            |xargs)
                required_software='GNU Findutils'
                ;;
            sed)
                required_software='GNU Sed'
                ;;
            *)
                required_software="${required_command}"
                ;;
        esac

        printf -- \
            'Error: This program requires "%s" to be installed and its executables in the executable searching paths.\n' \
            "${required_software}" \
            1>&2
        unset required_software
    fi
done; unset required_command required_software

if [ "${runtime_dependency_checking_result}" = fail ]; then
    printf -- \
        'Error: Runtime dependency checking fail, the progrom cannot continue.\n' \
        1>&2
    exit 1
fi; unset runtime_dependency_checking_result

## Non-overridable Primitive Variables
## BASHDOC: Shell Variables » Bash Variables
## BASHDOC: Basic Shell Features » Shell Parameters » Special Parameters
if [ -v 'BASH_SOURCE[0]' ]; then
    RUNTIME_EXECUTABLE_PATH="$(realpath --strip "${BASH_SOURCE[0]}")"
    RUNTIME_EXECUTABLE_FILENAME="$(basename "${RUNTIME_EXECUTABLE_PATH}")"
    RUNTIME_EXECUTABLE_NAME="${RUNTIME_EXECUTABLE_FILENAME%.*}"
    RUNTIME_EXECUTABLE_DIRECTORY="$(dirname "${RUNTIME_EXECUTABLE_PATH}")"
    RUNTIME_COMMANDLINE_BASECOMMAND="${0}"
    # We intentionally leaves these variables for script developers
    # shellcheck disable=SC2034
    declare -r \
        RUNTIME_EXECUTABLE_PATH \
        RUNTIME_EXECUTABLE_FILENAME \
        RUNTIME_EXECUTABLE_NAME \
        RUNTIME_EXECUTABLE_DIRECTORY \
        RUNTIME_COMMANDLINE_BASECOMMAND
fi
declare -ar RUNTIME_COMMANDLINE_ARGUMENTS=("${@}")

## init function: entrypoint of main program
## This function is called near the end of the file,
## with the script's command-line parameters as arguments
init(){
    if ! process_commandline_arguments; then
        printf -- \
            'Error: Invalid command-line parameters.\n' \
            1>&2

        printf '\n' # separate error message and help message
        print_help
        exit 1
    fi

    if ! test -v SNAPCRAFT_PRIME \
        || test "${PWD}" != "${SNAPCRAFT_PRIME}"; then
        printf -- \
            "%s: Error: This script should be run by \`snapcraft\` in the \`override-prime\` scriptlet.\\n" \
            "${RUNTIME_EXECUTABLE_NAME}"
        exit 1
    fi

    if test -d share/applications; then
        find \
            share/applications \
            -name '*.desktop' \
            -print0 \
            | xargs \
            --no-run-if-empty \
            --null \
            --verbose \
            sed \
            --file "${RUNTIME_EXECUTABLE_DIRECTORY}"/patch-desktop-entries.sed \
            --in-place
    fi

    exit 0
}; declare -fr init

print_help(){
    # Backticks in help message is Markdown's <code> markup
    # shellcheck disable=SC2016
    {
        printf '# Help Information for %s #\n' \
            "${RUNTIME_COMMANDLINE_BASECOMMAND}"
        printf '## SYNOPSIS ##\n'
        printf '* `"%s" _command-line_options_`\n\n' \
            "${RUNTIME_COMMANDLINE_BASECOMMAND}"

        printf '## COMMAND-LINE OPTIONS ##\n'
        printf '### `-d` / `--debug` ###\n'
        printf 'Enable script debugging\n\n'

        printf '### `-h` / `--help` ###\n'
        printf 'Print this message\n\n'
    }
    return 0
}; declare -fr print_help;

process_commandline_arguments() {
    if [ "${#RUNTIME_COMMANDLINE_ARGUMENTS[@]}" -eq 0 ]; then
        return 0
    fi

    # Modifyable parameters for parsing by consuming
    local -a parameters=("${RUNTIME_COMMANDLINE_ARGUMENTS[@]}")

    # Normally we won't want debug traces to appear during parameter parsing, so we add this flag and defer its activation till returning(Y: Do debug)
    local enable_debug=N

    while true; do
        if [ "${#parameters[@]}" -eq 0 ]; then
            break
        else
            case "${parameters[0]}" in
                --debug \
                |-d)
                    enable_debug=Y
                    ;;
                --help \
                |-h)
                    print_help;
                    exit 0
                    ;;
                *)
                    printf -- \
                        '%s: Error: Unknown command-line argument "%s"\n' \
                        "${FUNCNAME[0]}" \
                        "${parameters[0]}" \
                        >&2
                    return 1
                    ;;
            esac
            # shift array by 1 = unset 1st then repack
            unset 'parameters[0]'
            if [ "${#parameters[@]}" -ne 0 ]; then
                parameters=("${parameters[@]}")
            fi
        fi
    done

    if [ "${enable_debug}" = Y ]; then
        trap 'trap_return "${FUNCNAME[0]}"' RETURN
        set -o xtrace
    fi
    return 0
}; declare -fr process_commandline_arguments

## Traps: Functions that are triggered when certain condition occurred
## Shell Builtin Commands » Bourne Shell Builtins » trap
trap_errexit(){
    printf \
        'An error occurred and the script is prematurely aborted\n' \
        1>&2
    return 0
}; declare -fr trap_errexit; trap trap_errexit ERR

trap_exit(){
    return 0
}; declare -fr trap_exit; trap trap_exit EXIT

trap_return(){
    local returning_function="${1}"

    printf \
        'DEBUG: %s: returning from %s\n' \
        "${FUNCNAME[0]}" \
        "${returning_function}" \
        1>&2
}; declare -fr trap_return

trap_interrupt(){
    printf '\n' # Separate previous output
    printf \
        'Recieved SIGINT, script is interrupted.' \
        1>&2
    return 1
}; declare -fr trap_interrupt; trap trap_interrupt INT

init "${@}"
