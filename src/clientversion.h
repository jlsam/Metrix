// Copyright (c) 2009-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_CLIENTVERSION_H
#define BITCOIN_CLIENTVERSION_H

#if defined(HAVE_CONFIG_H)
#include "config/bitcoin-config.h"
#else
/**
* client versioning
*/

/** These need to be macros, as version.cpp's and bitcoin*-res.rc's voodoo requires it */
#define CLIENT_VERSION_MAJOR       3
#define CLIENT_VERSION_MINOR       4
#define CLIENT_VERSION_REVISION    7
#define CLIENT_VERSION_BUILD       0

/** Set to true for release, false for prerelease or test build */
#define CLIENT_VERSION_IS_RELEASE  true

/** Copyright year (2018-this) */
/** Todo: update this when changing our copyright comments in the source */
#define COPYRIGHT_YEAR 2020

#endif //HAVE_CONFIG_H

/** Converts the parameter X to a string after macro replacement on X has been performed. */
/** Don't merge these into one macro! */
#define STRINGIZE(X) DO_STRINGIZE(X)
#define DO_STRINGIZE(X) #X

#define COPYRIGHT_STR          "2018-" STRINGIZE(COPYRIGHT_YEAR) " Metrix developers"


#if !defined(WINDRES_PREPROC)

#include <string>
#include <vector>

static const int CLIENT_VERSION =
                           1000000 * CLIENT_VERSION_MAJOR
                         +   10000 * CLIENT_VERSION_MINOR
                         +     100 * CLIENT_VERSION_REVISION
                         +       1 * CLIENT_VERSION_BUILD;

extern const std::string CLIENT_NAME;
extern const std::string CLIENT_BUILD;
extern const std::string CLIENT_DATE;

std::string FormatFullVersion();
std::string FormatSubVersion(const std::string& name, int nClientVersion, const std::vector<std::string>& comments);

#endif // WINDRES_PREPROC

#endif // BITCOIN_CLIENTVERSION_H
