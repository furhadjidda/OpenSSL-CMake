/*
 * Copyright 1995-2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include "internal/cryptlib.h"

//#include "buildinf.h"

unsigned long OpenSSL_version_num(void)
{
    return 1;
}

const char *OpenSSL_version(int t)
{
    switch (t) {
    case OPENSSL_VERSION:
        return "1.1";
    case OPENSSL_BUILT_ON:
        return "1";
    case OPENSSL_CFLAGS:
        return "";
    case OPENSSL_PLATFORM:
        return "";
    case OPENSSL_DIR:
#ifdef OPENSSLDIR
        return "OPENSSLDIR: \"" OPENSSLDIR "\"";
#else
        return "OPENSSLDIR: N/A";
#endif
    case OPENSSL_ENGINES_DIR:
#ifdef ENGINESDIR
        return "ENGINESDIR: \"" ENGINESDIR "\"";
#else
        return "ENGINESDIR: N/A";
#endif
    }
    return "not available";
}
