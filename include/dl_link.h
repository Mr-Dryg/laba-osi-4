#pragma once

typedef struct
{
    int realiz;
    void* handle;
    double (*E)(int x);
    char* (*translation)(long x);
} DLibrary;

int link_lib(DLibrary* lib, const char* filename);
DLibrary* create_lib();
void destroy_lib(DLibrary* lib);
void switch_lib(DLibrary* lib);
