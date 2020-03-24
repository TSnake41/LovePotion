#include "common/runtime.h"
#include <sys/stat.h>

#include "objects/file/file.h"

File::File(const char * path) : Object("File")
{
    this->path = strdup(path);
    this->open = false;
    this->mode = nullptr;
}

File::File(const char * path, const char * mode) : Object("File")
{
    this->path = strdup(path);
    this->open = false;
    this->mode = nullptr;

    this->Open(mode);
}

File::~File()
{
    free(this->path);

    if (this->mode)
        free(this->mode);

    this->Close();
}

size_t File::GetSize()
{
    size_t size = 0;

    fseek(this->fileHandle, 0, SEEK_END);
    size = (size_t)ftell(this->fileHandle);
    rewind(this->fileHandle);

    return size;
}

const char * File::GetMode()
{
    return this->mode;
}

bool File::IsOpen()
{
    return this->open;
}

bool File::Open(const char * mode)
{
    this->fileHandle = fopen(this->path, mode);

    if (!this->fileHandle)
        return false;

    this->mode = strdup(mode);
    this->open = true;

    return true;
}

void File::Write(const char * data, size_t length)
{
    if (!this->open || (this->mode[0] != 'w'))
    {
        Love::RaiseError("Cannot write to file %s. File not open for writing.", this->path);
        return;
    }

    fwrite(data, length, 1, this->fileHandle);
}

void File::Flush()
{
    fflush(this->fileHandle);
}

void File::Close()
{
    if (this->open) {
        fclose(this->fileHandle);
        this->open = false;
    }
}

char *File::Read(size_t &size)
{
    if (!this->open || (strncmp(this->mode, "r", 1) != 0))
    {
        Love::RaiseError("Cannot read file %s. File not open for reading.", this->path);
        return NULL;
    }

    size = this->GetSize();
    char *buffer = (char *)malloc(size);

    if (!buffer)
        return nullptr;

    fread(buffer, size, 1, this->fileHandle);
    return buffer;
}
