#pragma once

class File : public Object
{
    public:
        File(const char * path);
        File(const char * path, const char * mode);

        File() {};
        ~File();

        char * Read(size_t &size);
        
        void Write(const char * data, size_t length);

        const char * GetMode();

        bool Open(const char * mode);
        bool IsOpen();
        void Flush();
        void Close();

        size_t GetSize();
    
    private:
        char * path;
        char * mode;

        FILE * fileHandle;
        bool open;
};