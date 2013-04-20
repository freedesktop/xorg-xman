/* $XConsortium: vendor.c,v 1.10 94/04/17 20:43:59 rws Exp $ */
/*

Copyright (c) 1987, 1988  X Consortium

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE X CONSORTIUM BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of the X Consortium shall
not be used in advertising or otherwise to promote the sale, use or
other dealings in this Software without prior written authorization
from the X Consortium.

*/
/* $XFree86: xc/programs/xman/vendor.c,v 1.2 2000/03/03 20:02:25 dawes Exp $ */

/* Vendor-specific data structures and operations */

#include "globals.h"
#include "vendor.h"

typedef struct sectionName {
    char *name;
    char *suffix;
} SectionNameRec;

#if (defined(SYSV) || defined(__osf__) || defined(SVR4)) && !defined(sun)

static SectionNameRec SectionNames[] = {
    {"(1) User Commands",               "1"},
    {"(1m) Sys, Administration",        "1m"},
    {"(2) System Calls",                "2"},
    {"(3) Subroutines",                 "3"},
    {"(4) File Formats",                "4"},
    {"(5) Miscellaneous",               "5"},
    {"(6) Games",                       "6"},
    {"(7) Devices",                     "7"},
    {"(8) Sys. Administration",         "8"},
    {"(l) Local",                       "l"},
    {"(n) New",                         "n"},
    {"(o) Old",                         "o"}
#ifdef __SCO__
    ,
    {"(ADM) System Administration", "ADM"},
    {"(ADMN) Network Administration", "ADMN"},
    {"(ADMP) Protocol Administration", "ADMP"},
    {"(C) Commands", "C"},
    {"(CMD) DOS Commands", "CMD"},
    {"(CP) Programming Commands", "CP"},
    {"(DOS) DOS Subroutines and Libraries", "DOS"},
    {"(F) File Formats", "F"},
    {"(HW) Hardware Dependant", "HW"},
    {"(K) Kernel Subroutines", "K"},
    {"(LOCAL) Local utilities for your system", "LOCAL"},
    {"(M) Miscellaneous", "M"},
    {"(NADM) NFS Administration", "NADM"},
    {"(NC) Network Commands", "NC"},
    {"(NF) Network File Formats", "NF"},
    {"(NS) Network Subroutines", "NS"},
    {"(NSL) Network Services", "NSL"},
    {"(S) Subroutines and Libraries", "S"},
    {"(SCO) Product Engineering Toolkit", "SCO"},
    {"(SFF) Socket File Formats", "SFF"},
    {"(STR) Streams", "STR"},
    {"(TC) Transport Layer Commands", "TC"},
    {"(X) X Man pages", "X"},
    {"(XNX) Xenix Subroutines, Commands and Libs", "XNX"},
    {"(XS) X11 Subroutines and Libraries", "XS"},
    {"(Xm) Motif Commands and Subroutines", "Xm"},
    {"(Xt) X Intrinsics", "Xt"}
#endif
};

#else

#if defined(sun) && defined(SVR4)
/* losing man.cf is useless because it has no section names */

static SectionNameRec SectionNames[] = {
    {"(1)  User Commands",                      "1"},
    {"(1b) SunOS/BSD Compatibility Commands",   "1b"},
    {"(1c) Communication Commands",             "1c"},
    {"(1f) FMLI Commands",                      "1f"},
    {"(1m) Maintenance Commands",               "1m"},
    {"(1s) SunOS Specific Commands",            "1s"},
    {"(2)  System Calls",                       "2"},
    {"(3)  C Library Functions",                "3"},
    {"(3b) SunOS/BSD Compatibility Functions",  "3b"},
    {"(3c) C Library Functions",                "3c"},
    {"(3e) ELF Library Functions",              "3e"},
    {"(3g) C Library Functions",                "3g"},
    {"(3i) Wide Character Functions",           "3i"},
    {"(3k) Kernel VM Library Functions",        "3k"},
    {"(3m) Mathematical Library",               "3m"},
    {"(3n) Network Functions",                  "3n"},
    {"(3r) RPC Services Library",               "3r"},
    {"(3s) Standard I/O Functions",             "3s"},
#if OSMINORVERSION == 5
    {"(3t) Threads Library",                    "3t"},
#endif
    {"(3x) Miscellaneous Library Functions",    "3x"},
    {"(4)  File Formats",                       "4"},
    {"(4b) Misc. Reference Manual Pages",       "4b"},
    {"(5)  Environments, Tables, and TROFF Macros", "5"},
    {"(6)  Games and Demos",                    "6"},
    {"(7)  Special Files",                      "7"},
#if OSMINORVERSION == 5
    {"(7d)  Devices",                           "7d"},
    {"(7fs) File Systems",                      "7fs"},
    {"(7i)  Ioctl Requests",                    "7i"},
    {"(7m)  STREAMS Modules",                   "7m"},
    {"(7p)  Protocols",                         "7p"},
#endif
    {"(9)  Device Driver Information",          "9"},
    {"(9e) DDI and DKI Driver Entry Points",    "9e"},
    {"(9f) DDI and DKI Kernel Functions",       "9f"},
    {"(9s) DDI and DKI Data Structures",        "9s"},
    {"(l)  Local",                              "l"},
    {"(n)  New",                                "n"},
};

#else

static SectionNameRec SectionNames[] = {
    {"(1) User Commands",                       "1"},
    {"(2) System Calls",                        "2"},
    {"(3) Subroutines",                         "3"},
    {"(4) Devices",                             "4"},
    {"(5) File Formats",                        "5"},
    {"(6) Games",                               "6"},
    {"(7) Miscellaneous",                       "7"},
    {"(8) Sys. Administration",                 "8"},
#ifdef Lynx
    {"(9) Device driver service calls",         "9"},
#endif
#if defined(__OpenBSD__) || defined(__NetBSD__)
    {"(9) Kernel Manual",                       "9"},
#endif
#if defined(__FreeBSD__)
    {"(9) Kernel Interfaces",                   "9"},
#endif
    {"(l) Local",                               "l"},
    {"(n) New",                                 "n"},
    {"(o) Old",                                 "o"},
#ifdef sony
    {"(p) Public Domain",                       "p"},
    {"(s) Sony Specific",                       "s"},
#endif
};

#endif
#endif

/*	Function Name: AddStandardSections
 *	Description: Adds all the standard sections to the list for this path.
 *	Arguments: list - a pointer to the section list.
 *                 path - the path to these standard sections.
 *	Returns: none.
 */

void
AddStandardSections(SectionList ** list, char *path)
{
    register int i;
    char file[BUFSIZ];
    int numSections = sizeof(SectionNames) / sizeof(SectionNames[0]);

    for (i = 0; i < numSections; i++) {
        snprintf(file, sizeof(file), "%s%s", SEARCHDIR, SectionNames[i].suffix);
        AddNewSection(list, path, file, SectionNames[i].name, TRUE);
#ifdef SEARCHOTHER
        snprintf(file, sizeof(file), "%s%s", SEARCHOTHER,
                 SectionNames[i].suffix);
        AddNewSection(list, path, file, SectionNames[i].name, TRUE);
#endif
    }
}



/*	Function Name: CreateManpageName
 *	Description: Creates the manual page name for a given item.
 *	Arguments: entry - the entry to convert.
 *	Returns: the manual page properly allocated.
 */

/*
 * If the filename is foo.3     - Create an entry of the form:  foo
 * If the filename is foo.3X11  - Create an entry of the form:  foo(X11)
 * IF the filename is a.out.1   - Create an entry of the form:  a.out
 */

char *
CreateManpageName(char *entry, int section,     /* FIXME: unused */
                  int flags)
{
    char *cp;
    char page[BUFSIZ];
    char sect[BUFSIZ];

    ParseEntry(entry, NULL, sect, page);

    if ((cp = rindex(page, '.')) != NULL) {
        if ((int) strlen(cp) > 2) {
            *cp++ = '(';
            while ((cp[1] != '\0')) {
                *cp = *(cp + 1);
                cp++;
            }
            *cp++ = ')';
            *cp = '\0';
        }
        else
            *cp = '\0';
    }


    return (StrAlloc(page));
}
