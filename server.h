#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <getopt.h>

#define MAX_LINE                4096
#define DEFAULT_DOCUMENT_ROOT   "./"
#define DEFAULT_LOG_PATH        "/tmp/mini_server.log"

static unsigned short g_is_debug = 0;
static unsigned int   g_port     = 8888;
static unsigned short g_is_log   = 0;
static char g_doc_root[256]      = DEFAULT_DOCUMENT_ROOT;
static char g_log_path[256]      = DEFAULT_LOG_PATH;
