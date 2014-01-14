#include "server.h"

/**
 * parse options
 */
static int parse_options(int argc, char **argv)
{
    int opt;
    struct option longopts[] = {
        {"is_debug",    0,  NULL,   'd'},
        {"port",        1,  NULL,   'p'},
        {"is_log",      0,  NULL,   'l'},
        {NULL,          0,  NULL,     0}
    };
    
    while (-1 != (opt = getopt_long(argc, argv, "dp:l", longopts, NULL))) {
        switch (opt) {
            case 'd':
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
                printf("h\n");
                //TODO printf usage
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
