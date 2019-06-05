//
// src/usage.c
// tbd
//
// Created by inoahdev on 11/18/18.
// Copyright © 2018 - 2019 inoahdev. All rights reserved.
//

#include <stdio.h>

void print_usage(void) {
    fputs("Usage: tbd [-p/--path] [path-options] [file-paths] [-o/--output] [output-options] [output-paths]\n", stdout);
    fputs("Main options:\n", stdout);
    fputs("    -h, --help,   Print this message\n", stdout);
    fputs("    -o, --output, Path to an output file (or directory for recursing/dyld_shared_cache files) to write converted tbd files.\n", stdout);
    fputs("                  If provided file(s) already exists, contents will be overridden.\n", stdout);
    fputs("                  Can also provide \"stdout\" to print to stdout\n", stdout);
    fputs("    -p, --path,   Path to a mach-o or dyld_shared_cache file to convert to a tbd file.\n", stdout);
    fputs("                  Can also provide \"stdin\" to use stdin.\n", stdout);
    fputs("    -u, --usage,  Print this message\n", stdout);

    fputc('\n', stdout);
    fputs("Path options:\n", stdout);
    fputs("Usage: tbd [-p] [options] path\n", stdout);
    fputs("    -r, --recurse, Specify directory to recurse and find all mach-o library and dyld_shared_cache images\n", stdout);
    fputs("                   Two modes exist for recursing:\n", stdout);
    fputs("                       once, Recurse only the top-level directory. This is the default case for recursing\n", stdout);
    fputs("                       all,  Recurse both the top-level directory and sub-directories\n", stdout);

    fputc('\n', stdout);
    fputs("Outputting options:\n", stdout);
    fputs("Usage: tbd -o [options] path\n", stdout);
    fputs("        --preserve-subdirs,       Preserve the sub-directories of where files were found\n", stdout);
    fputs("                                  when recursing in relation to the actual provided recurse-path\n", stdout);
    fputs("        --no-overwrite,           Prevent overwriting of files when writing out\n", stdout);
    fputs("        --replace-path-extension, Replace the path-extension(s) of provided file(s) when\n", stdout);
    fputs("                                  writing out (Instead of simply appending .tbd)\n", stdout);

    fputc('\n', stdout);
    fputs("Both local and global options:\n", stdout);
    fputs("        --macho,                                 Specify that the file(s) provided should only be parsed\n", stdout);
    fputs("                                                 if it is a mach-o file\n", stdout);
    fputs("                                                 This option can be used to limit the filetypes parsed\n", stdout);
    fputs("                                                 while recursing\n", stdout);
    fputs("        --dsc,                                   Specify that the file(s) provided should only be parsed\n", stdout);
    fputs("                                                 if it is a dyld-shared-cache file.\n", stdout);
    fputs("                                                 Providing --macho or --dsc limits filetypes parsed when recursing\n", stdout);
    fputs("                       --filter-image-directory, Specify a directory to filter dyld_shared_cache images from\n", stdout);
    fputs("                       --filter-image-filename,  Specify a filename to filter dyld_shared_cache images from\n", stdout);
    fputs("                       --filter-image-number,    Specify the number of an dyld_shared_cache image to parse out.\n", stdout);
    fputs("                                                 To get the numbers of all available images, use the option --list-dsc-images\n", stdout);
    fputs("                       --image-path,             Specify the path of an image to parse out.\n", stdout);
    fputs("                                                 To get the paths of all available images, use the option --list-dsc-images\n", stdout);
    fputs("        -v, --version,                           Specify version of .tbd files to convert to (default is v2).\n", stdout);
    fputs("                                                 This applies to all files where tbd-version was not explicitly set.\n", stdout);
    fputs("                                                 To get a list of all available versions, use the option --list-tbd-versions\n", stdout);

    fputc('\n', stdout);
    fputs("Ignore options:\n", stdout);
    fputs("        --ignore-clients,               Ignore clients field\n", stdout);
    fputs("        --ignore-compatibility-version, Ignore compatibility-version field\n", stdout);
    fputs("        --ignore-current-version,       Ignore current-version field\n", stdout);
    fputs("        --ignore-exports,               Ignore exports field\n", stdout);
    fputs("        --ignore-objc-constraint,       Ignore objc-constraint field\n", stdout);
    fputs("        --ignore-parent-umbrella        Ignore parent-umbrella field\n", stdout);
    fputs("        --ignore-reexports,             Ignore re-expotrs field\n", stdout);
    fputs("        --ignore-swift-version,         Ignore swift-version field\n", stdout);
    fputs("        --ignore-uuids,                 Ignore uuids field\n", stdout);

    fputc('\n', stdout);
    fputs("General ignore options:\n", stdout);
    fputs("        --ignore-requests,    Ignore requests of all kinds (both path and global option)\n", stdout);
    fputs("        --ignore-warnings,    Ignore any warnings (both path and global option)\n", stdout);

    fputc('\n', stdout);
    fputs("Symbol options: (Both path and global options)\n", stdout);
    fputs("        --allow-all-private-symbols,    Allow all non-external symbols (Not guaranteed to link at runtime)\n", stdout);
    fputs("        --allow-private-normal-symbols, Allow all non-external symbols (Not guaranteed to link at runtime)\n", stdout);
    fputs("        --allow-private-weak-symbols,   Allow all non-external weak symbols (Not guaranteed to link at runtime)\n", stdout);
    fputs("        --allow-private-objc-symbols,   Allow all non-external objc-classes and ivars\n", stdout);
    fputs("        --allow-private-objc-classes,   Allow all non-external objc-classes\n", stdout);
    fputs("        --allow-private-objc-ehtypes,   Allow all non-external objc eh-types\n", stdout);
    fputs("        --allow-private-objc-ivars,     Allow all non-external objc-ivars\n", stdout);

    fputc('\n', stdout);
    fputs("Field options: (Both path and global options)\n", stdout);
    fputs("        --add-archs,               Provide architecture(s) to add onto architectures found for .tbd files\n", stdout);
    fputs("                                   A list of architectures can be found by using option --list-architectures\n", stdout);
    fputs("        --remove-archs,            Provide architecture(s) to remove from architectures found for .tbd files\n", stdout);
    fputs("                                   A list of architectures can be found by using option --list-architectures\n", stdout);
    fputs("        --replace-archs,           Provide architecture(s) to replace architectures found for .tbd files\n", stdout);
    fputs("                                   A list of architectures can be found by using option --list-architectures\n", stdout);
    fputs("        --add-flags,               Provide flag(s) to add onto flags found for .tbd files\n", stdout);
    fputs("                                   A list of flags can be found by using option --list-tbd-flags\n", stdout);
    fputs("        --remove-flags,            Provide flag(s) to remove from flags found for .tbd files\n", stdout);
    fputs("                                   A list of flags can be found by using option --list-tbd-flags\n", stdout);
    fputs("        --replace-flags,           Provide flag(s) to replace flags found for .tbd files\n", stdout);
    fputs("                                   A list of flags can be found by using option --list-tbd-flags\n", stdout);
    fputs("        --replace-objc-constraint, Provide an objc-constraint to replace the one found for .tbd files\n", stdout);
    fputs("        --replace-platform,        Provide a platform to replace the one found for .tbd files\n", stdout);
    fputs("        --replace-swift-version,   Provide a swift-version to replace the one found for .tbd files\n", stdout);

    fputc('\n', stdout);
    fputs("Ignore field warning options: (Both path and global options)\n", stdout);
    fputs("        --ignore-missing-exports,  Ignore error for when no symbols or reexpors to write out\n", stdout);
    fputs("                                   are found\n", stdout);
    fputs("        --ignore-missing-uuids,    Ignore error for when uuids are not found\n", stdout);
    fputs("        --ignore-non-unique-uuids, Ignore error for when uuids found are not unique among one another\n", stdout);

    fputc('\n', stdout);
    fputs("List options:\n", stdout);
    fputs("        --list-architectures,    List all valid architectures for .tbd files.\n", stdout);
    fputs("                                 Also able to list architectures of the mach-o file from a provided path\n", stdout);
    fputs("        --list-dsc-images,       List all images of a dyld_shared_cache from a provided path\n", stdout);
    fputs("                                 One option exists for listing dsc-images:\n", stdout);
    fputs("                                     --ordered, Order image-paths alphabetically before printing them. An image-path's listed\n", stdout);
    fputs("                                                number should not be provided for option --filter-image-number\n", stdout);
    fputs("        --list-objc-constraints, List all valid objc-constraint options for .tbd files\n", stdout);
    fputs("        --list-platform,         List all valid platforms\n", stdout);
    fputs("        --list-tbd-flags,        List all valid flags for .tbd files\n", stdout);
    fputs("        --list-tbd-versions,     List all valid versions for .tbd files\n", stdout);
}
