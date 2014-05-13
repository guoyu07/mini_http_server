#include "server.h"

/**
 * show help
 */
static int show_help()
{
    fprintf(stderr, "\n********* Http Mini Server **********\n\n");
    fprintf(stderr, "Usage: ./server [OPTION] ...\n\n");
    fprintf(stderr, "Options:\n");
    fprintf(stderr, "-D, --is_debig      Is open debug mode, default No\n");
    fprintf(stderr, "-p, --port=PORT     Server listen port, default 80\n");
    fprintf(stderr, "-l, --is_log        Is write access log, default No\n");
    fprintf(stderr, "\n*************************************\n");
}

/**
 * parse options
 */
static int parse_options(int argc, char **argv)
{
    int opt;
    struct option longopts[] = {
        {"is_debug",    0,  NULL,   'D'},
        {"port",        1,  NULL,   'p'},
        {"is_log",      0,  NULL,   'l'},
        {NULL,          0,  NULL,     0}
    };
    
    while (-1 != (opt = getopt_long(argc, argv, "dp:l", longopts, NULL))) {
        switch (opt) {
            case 'D':
                g_is_debug = 1;
                break;
            case 'p':
                g_port = atoi(optarg);
                if (g_port < 1 || g_port > 65535) {
                    fprintf(stderr, "Error:Options -p,--port error: input port number %d invalid, must between 1 - 65535.\n\n", g_port);
                    return -1;
                }
                break;
            case 'l':
                g_is_log = 1;
                break;
            default:
                show_help();
        }
    }

    return 0;
}


int main(int argc, char **argv)
{
    if (argc > 1) {
        if (0 != parse_options(argc, argv)) {
            exit(-1);
        }
    }
    printf("debug=%d\tport=%d\tlog=%d\n", g_is_debug, g_port, g_is_log);

    return 0;
}
