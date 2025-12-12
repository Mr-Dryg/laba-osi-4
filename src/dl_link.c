#include "../include/dl_link.h"
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

#define PATH_1 "src/librealiz_1.so"
#define PATH_2 "src/librealiz_2.so"

int link_lib(DLibrary* lib, const char* filename)
{
    lib->handle = dlopen(filename, RTLD_NOW);
    if (lib->handle == NULL)
    {
        fprintf(stderr, "dlopen error: %s\n", dlerror());
        return 0;
    }

    lib->E = dlsym(lib->handle, "E");
    if (lib->E == NULL)
    {
        fprintf(stderr, "get func \"E\" error: %s\n", dlerror());
        dlclose(lib->handle);
        return 0;
    }

    lib->translation = dlsym(lib->handle, "translation");
    if (lib->translation == NULL)
    {
        fprintf(stderr, "get func \"translation\" error: %s\n", dlerror());
        dlclose(lib->handle);
        return 0;
    }
    return 1;
}

DLibrary* create_lib()
{
    DLibrary* lib = malloc(sizeof(DLibrary));
    if (lib == NULL)
    {
        perror("malloc for DLibrary error");
        return NULL;
    }

    if (!link_lib(lib, PATH_1))
    {
        free(lib);
        return NULL;
    }
    lib->realiz = 1;
    return lib;
}

void destroy_lib(DLibrary* lib)
{
    dlclose(lib->handle);
    free(lib);
}

void switch_lib(DLibrary* lib)
{
    dlclose(lib->handle);
    if (lib->realiz == 1)
    {
        link_lib(lib, PATH_2);
        lib->realiz = 2;
    }
    else if (lib->realiz == 2)
    {
        link_lib(lib, PATH_1);
        lib->realiz = 1;
    }
}