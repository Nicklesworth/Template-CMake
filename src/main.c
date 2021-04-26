#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <getopt.h>
#include "config.h"

/* Flag set by ‘--verbose’. */
static int verbose;
static char *project_name = PROJECT_NAME;

void printVersion(void)
{
    printf("%s v%i.%i.%i\n", project_name, PROJECT_VERSION_MAJOR, PROJECT_VERSION_MINOR, PROJECT_VERSION_PATCH);
    printf("License: The Unlicense - This is free and unencumbered software released into the public domain.\n");
}

void printUsage(void)
{
    printf("usage: %s [options] ]\n", project_name);
    printf("[options]:\n");
    printf("  --help (-h)       outputs this usage info\n");
    printf("  --version (-v)    outputs version info\n");
    printf("  --verbose         enables verbose output for debugging\n");
    printf("  --brief           disables verbose output\n");
}

int main(int argc, char **argv)
{
    // Flags
    int error = 0;

    // Application configuration
    int mode;

    // Long Options
    static struct option long_options[] =
    {
        {"verbose" , no_argument , &verbose , 1   },
        {"brief"   , no_argument , &verbose , 0   },
        {"help"    , no_argument , NULL     , 'h' },
        {"version" , no_argument , NULL     , 'v' },
        {0         , 0           , 0        , 0   }
    };

    // Short options
    static char *short_options = "hv";

    // Command Line Option Parsing
    int c, idx;
    while ((c = getopt_long(argc, argv, short_options, long_options, &idx)) != -1)
    {
        switch (c)
        {
        // Flag type option, nothing to do
        case 0:
            break;

        // Help
        case 'h':
            printVersion();
            printUsage();
            exit(error);
            break;

        // Version Info
        case 'v':
            printVersion();
            exit(error);
            break;

        case '?':
            break;

        default:
            abort();
        }
    }

    // Verbose Output
    if(verbose)
    {
        printVersion();
    }

    exit(error);
}
