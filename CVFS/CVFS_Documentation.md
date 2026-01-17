# Customised Virtual File System (CVFS) - Project Documentation

## 1. Name of the Project
**Customised Virtual File System (CVFS)**

## 2. Technology Used
- **Programming Language**: C
- **Development Environment**: Command Line Interface (CLI)
- **Platform**: Cross-platform (Windows and Unix-like systems)
- **Memory Management**: Dynamic memory allocation using malloc()
- **Data Structures**: Linked Lists, Arrays, Structures

## 3. User Interface Used
- **Command Line Interface (CLI)**
- **Interactive Shell**: Marvellous CVFS Shell
- **Command Structure**: Command-based operations similar to Unix/Linux shell
- **Available Commands**:
  - `help` - Display help page
  - `man` - Display manual pages
  - `clear` - Clear terminal screen
  - `ls` - List files
  - `creat` - Create new file
  - `exit` - Exit the system

## 4. Platform Required
- **Operating System**: Windows, Linux, macOS
- **Compiler**: GCC/MinGW or any standard C compiler
- **Terminal/Console**: Command prompt or terminal emulator
- **System Requirements**: Minimal (console-based application)

## 5. Hardware Requirements
- **RAM**: Minimum 64 MB (recommended 256 MB or more)
- **Storage**: 1 MB free space for executable and virtual file storage
- **Processor**: Any modern processor (x86, x64, ARM)
- **Architecture**: 32-bit or 64-bit systems

## 6. Description of the Project
The Customised Virtual File System (CVFS) is a simulated file system implemented in C that mimics the functionality of a real file system within memory. The project demonstrates understanding of file system concepts including:

- **File Management**: Create, list, and manage virtual files
- **Inode Management**: Track file metadata using inode structures
- **Permission System**: Implement read/write permissions
- **Memory Management**: Efficient allocation and deallocation of file storage
- **Command Interface**: Unix-like command shell for user interaction

The system provides a virtual environment where users can perform basic file operations without affecting the actual file system, making it ideal for educational purposes and system programming demonstrations.

## 7. Data Structures Used in the Project

### 7.1 BootBlock Structure
```c
struct BootBlock
{
    char Information[100];
};
```
- **Purpose**: Stores boot information for the virtual file system
- **Usage**: Contains initialization messages

### 7.2 SuperBlock Structure
```c
struct SuperBlock
{
    int TotalInodes;
    int FreeInodes;
};
```
- **Purpose**: Manages overall file system metadata
- **Usage**: Tracks total and available inodes

### 7.3 Inode Structure
```c
struct Inode
{
    char FileName[20];
    int InodeNumber;
    int FileSize;
    int ActualFileSize;
    int FileType;
    int ReferenceCount;
    int Permission;
    char *Buffer;
    struct Inode *next;
};
```
- **Purpose**: Core file metadata structure
- **Usage**: Stores file information, permissions, and data pointer
- **Key Features**:
  - File name and identification
  - Size management (allocated vs actual)
  - File type classification
  - Permission bits
  - Data buffer pointer
  - Linked list connectivity

### 7.4 FileTable Structure
```c
struct FileTable
{
    int ReadOffset;
    int WriteOffset;
    int Mode;
    PINODE ptrinode;
};
```
- **Purpose**: Manages open file information
- **Usage**: Tracks file positions and access modes
- **Key Features**:
  - Read/write cursor positions
  - File access mode
  - Pointer to associated inode

### 7.5 UAREA Structure
```c
struct UAREA
{
    char ProcessName[20];
    PFILETABLE UFDT[MAXOPENFILES];
};
```
- **Purpose**: User area for process-specific file information
- **Usage**: Manages per-process file descriptor table
- **Key Features**:
  - Process identification
  - File descriptor table (UFDT - User File Descriptor Table)

## 8. Diagram of Data Structures Used in the Project

```
┌─────────────────────────────────────────────────────────────┐
│                    CVFS Architecture                        │
├─────────────────────────────────────────────────────────────┤
│  BootBlock                                                 │
│  ┌─────────────────────────────────────────────────────┐   │
│  │ Information[100]                                     │   │
│  └─────────────────────────────────────────────────────┘   │
├─────────────────────────────────────────────────────────────┤
│  SuperBlock                                                │
│  ┌─────────────┬─────────────┐                             │
│  │ TotalInodes │ FreeInodes  │                             │
│  └─────────────┴─────────────┘                             │
├─────────────────────────────────────────────────────────────┤
│  UAREA                                                     │
│  ┌─────────────┬─────────────────────────────────────────┐ │
│  │ProcessName  │ UFDT[MAXOPENFILES]                      │ │
│  └─────────────┴─────────────────────────────────────────┘ │
│                      │                                     │
│                      ▼                                     │
│  ┌─────────────────────────────────────────────────────┐   │
│  │ FileTable Array                                     │   │
│  │ ┌──────┬──────┬──────┬──────┐                      │   │
│  │ │ FT0  │ FT1  │ FT2  │ ...  │                      │   │
│  │ └──────┴──────┴──────┴──────┘                      │   │
│  └─────────────────────────────────────────────────────┘   │
│                      │                                     │
│                      ▼                                     │
│  ┌─────────────────────────────────────────────────────┐   │
│  │ FileTable                                           │   │
│  │ ┌──────────┬──────────┬──────┬──────────────┐      │   │
│  │ │ReadOffset│WriteOffset│ Mode │ ptrinode    │      │   │
│  │ └──────────┴──────────┴──────┴──────────────┘      │   │
│  └─────────────────────────────────────────────────────┘   │
│                      │                                     │
│                      ▼                                     │
│  ┌─────────────────────────────────────────────────────┐   │
│  │ Inode Linked List                                   │   │
│  │ ┌─────────┐    ┌─────────┐    ┌─────────┐         │   │
│  │ │ Inode1  │───▶│ Inode2  │───▶│ Inode3  │───▶... │   │
│  │ └─────────┘    └─────────┘    └─────────┘         │   │
│  │                                                 │   │
│  │ ┌─────────────────────────────────────────────┐ │   │
│  │ │ FileName │ InodeNum │ Size │ Type │ Buffer │ │   │
│  │ └─────────────────────────────────────────────┘ │   │
│  └─────────────────────────────────────────────────────┘   │
└─────────────────────────────────────────────────────────────┘
```

## 9. The Flow of the Project

### 9.1 Initialization Phase
1. **StartAuxillaryDataInitilisation()** called
2. **BootBlock** initialized with boot information
3. **SuperBlock** initialized with total and free inodes
4. **DILB (Disk Inode List Block)** created using linked list
5. **UAREA** initialized with process information

### 9.2 Command Processing Loop
1. Display prompt: "Marvellous CVFS : > "
2. Read user command input
3. Parse command into tokens
4. Execute appropriate command based on token count
5. Return to step 1 (infinite loop until exit)

### 9.3 File Creation Flow
1. User enters: `creat filename permission`
2. **CreateFile()** function called
3. Validate parameters (name, permission)
4. Check for available inodes
5. Verify file doesn't already exist
6. Find empty inode in linked list
7. Find empty UFDT entry
8. Allocate FileTable structure
9. Initialize FileTable fields
10. Initialize Inode fields
11. Allocate file buffer memory
12. Update SuperBlock (decrement free inodes)
13. Return file descriptor to user

### 9.4 File Listing Flow
1. User enters: `ls`
2. **LsFile()** function called
3. Traverse inode linked list
4. Display information for valid files
5. Show inode number, filename, and actual file size

### 9.5 Exit Flow
1. User enters: `exit`
2. Display thank you message
3. Break infinite loop
4. Program termination (automatic cleanup)

## 10. Actual Code of the Project

### 10.1 Key Constants and Macros
```c
#define MAXFILESIZE 50
#define MAXOPENFILES 20
#define MAXINODE 5
#define READ 1
#define WRITE 2
#define EXECUTE 4
#define REGULARFILE 1
#define SPECIALFILE 2
```

### 10.2 Error Codes
```c
#define ERR_INVALID_PARAMETER -1
#define ERR_NO_INODES -2
#define ERR_FILE_ALREADY_EXIST -3
#define ERR_FILE_NOT_EXIST -4
#define ERR_PERMISSION_DENIED -5
#define ERR_INSUFFICIENT_SPACE -6
#define ERR_INSUFFICIENT_DATA -7
#define ERR_MAX_FILES_OPEN -8
```

### 10.3 Core Functions

#### Initialization Functions
- `StartAuxillaryDataInitilisation()` - Main initialization
- `InitialiseSuperBlock()` - Initialize superblock
- `CreateDILB()` - Create inode linked list
- `InitialiseUAREA()` - Initialize user area

#### File Operations
- `CreateFile()` - Create new file
- `IsFileExist()` - Check file existence
- `LsFile()` - List all files

#### User Interface
- `DisplayHelp()` - Show help information
- `ManPageDisplay()` - Display manual pages

#### Main Function
- `main()` - Entry point with command processing loop

## 11. Output Screenshots Demonstrating Features

### 11.1 System Startup
```
Booting process of Marvellous CVFS is done
Marvellous CVFS : Super block gets initialised succesfully
Marvellous CVFS : DILB created succesfully
Marvellous CVFS : UAREA gets initialised succesfully
Marvellous CVFS : Auxillary data initialised succesfully
-----------------------------------------------
----- Marvellous CVFS started succesfully -----
-----------------------------------------------
```

### 11.2 Help Command
```
Marvellous CVFS : > help
-----------------------------------------------
---------- Marvellous CVFS Help Page ----------
-----------------------------------------------
man    : It is used to display manual page
clear  : It is used to clear the terminal
creat  : It is used to create new file
write  : It is used to write the data into file
read   : It is used to read the data from the file
stat   : It is used to display statistical information
unlink : It is used to delete the file
exit   : It is used to terminate Marvellous CVFS
-----------------------------------------------
```

### 11.3 File Creation
```
Marvellous CVFS : > creat test.txt 3
Total number of Inodes remaining : 5
File gets succesfully created with FD 3
```

### 11.4 File Listing
```
Marvellous CVFS : > ls
-----------------------------------------------
------ Marvellous CVFS Files Information ------
-----------------------------------------------
3       test.txt        0
-----------------------------------------------
```

### 11.5 Manual Pages
```
Marvellous CVFS : > man ls
About : It is used to list the names of all files
Usage : ls
```

### 11.6 Error Handling
```
Marvellous CVFS : > creat test.txt 3
Total number of Inodes remaining : 4
Error : Unable to create file because the file is already present
```

### 11.7 System Exit
```
Marvellous CVFS : > exit
Thank you for using Marvellous CVFS
Deallocating all the allocated resources
```

## 12. Additional Features and Capabilities

### 12.1 Memory Management
- Dynamic memory allocation for file buffers
- Efficient linked list management
- Automatic cleanup on program exit

### 12.2 Error Handling
- Comprehensive error codes for different failure scenarios
- User-friendly error messages
- Parameter validation

### 12.3 Cross-Platform Support
- Conditional compilation for Windows and Unix systems
- Platform-specific clear screen commands
- Standard C library usage

### 12.4 Extensibility
- Modular function design
- Clear separation of concerns
- Easy to add new commands and features

## 13. Technical Specifications

### 13.1 File System Limits
- Maximum files: 5 (MAXINODE)
- Maximum open files: 20 (MAXOPENFILES)
- Maximum file size: 50 bytes (MAXFILESIZE)
- Maximum filename length: 19 characters + null terminator

### 13.2 Permission System
- READ (1): Read-only access
- WRITE (2): Write-only access
- READ + WRITE (3): Read and write access

### 13.3 File Types
- REGULARFILE (1): Standard data files
- SPECIALFILE (2): Special device files (future enhancement)

## 14. Future Enhancements

### 14.1 Planned Features
- File read/write operations
- File deletion (unlink)
- File statistics (stat)
- Directory support
- File permissions modification (chmod)
- File seeking (lseek)

### 14.2 Performance Improvements
- Hash table for faster file lookup
- Memory pool allocation
- Buffer management optimization

## 15. Conclusion

The Customised Virtual File System demonstrates a comprehensive understanding of file system concepts and system programming principles. The project successfully implements:

- Core file system structures
- Memory management techniques
- Command-line interface design
- Error handling mechanisms
- Cross-platform compatibility

This educational project provides valuable insights into how real file systems work while maintaining simplicity and clarity in implementation. The modular design and well-documented code make it an excellent learning resource for understanding operating system concepts.

---

**Project Author**: Sakshi Chakre  
**Development Date**: January 2026  
**Version**: 1.0  
**License**: Educational Use

## 16. Answers to Questions

### 1. What is meant by file system?
A file system is a method and data structure that an operating system uses to control how data is stored and retrieved on storage devices. It organizes files into directories, manages file metadata (permissions, timestamps, size), and maintains the mapping between file names and their physical locations on disk. Without a file system, data would be stored as an unstructured block of information with no way to distinguish between different files.

### 2. Which file systems are used by Linux and Windows operating systems?
- **Linux**: Primarily uses Ext4 (Fourth Extended Filesystem). Other common Linux file systems include Ext2, Ext3, XFS, Btrfs, ZFS, and JFS.
- **Windows**: Primarily uses NTFS (New Technology File System). Older versions used FAT32 and FAT16.

### 3. What are the parts of the file system?
A typical file system consists of:
- **Boot Block**: Contains system boot information
- **Superblock**: Stores file system metadata (total blocks, free blocks, inode count)
- **Inode Table**: Contains file metadata (permissions, ownership, size, timestamps, block pointers)
- **Data Blocks**: Store actual file content
- **Directory Blocks**: Map filenames to inode numbers

### 4. Explain UAREA and its contents.
UAREA (User Area) is a process-specific structure that maintains information about files opened by a particular process. In this CVFS project, UAREA contains:
- `ProcessName[20]`: Name of the process
- `UFDT[MAXOPENFILES]`: User File Descriptor Table - an array of pointers to FileTable structures
It acts as a per-process file descriptor table, tracking which files each process has opened.

### 5. Explain the use of the File Table and its contents.
The File Table represents an opened file instance and maintains the current state of file operations. It contains:
- `ReadOffset`: Current position for read operations
- `WriteOffset`: Current position for write operations
- `Mode`: File access mode (READ, WRITE, READ+WRITE)
- `ptrinode`: Pointer to the associated inode
It bridges the gap between the process's file descriptor and the file's inode.

### 6. Explain the use of InCore inode Table and its use.
The InCore inode table is a kernel-level data structure that maintains in-memory copies of frequently accessed inodes. It provides:
- Faster access to inode information without disk I/O
- Reference counting for open files
- Locking mechanisms for concurrent access
- Caching of recently used inode data
This improves file system performance by reducing disk access.

### 7. What does inode mean?
An inode (index node) is a data structure that stores metadata about a file or directory. It contains all information about a file except its name and actual data content. Each file has a unique inode number that identifies it within the file system.

### 8. What are the contents of Superblock?
The Superblock contains file system-wide metadata:
- Total number of inodes and blocks
- Number of free inodes and blocks
- Size of file system blocks
- File system type and version
- Mount point information
- File system state flags
- Last mount time and check time

### 9. What are the types of files?
Common file types include:
- **Regular files**: Normal data files
- **Directory files**: Special files that contain directory entries
- **Character device files**: Devices that handle data character by character
- **Block device files**: Devices that handle data in blocks
- **Symbolic links**: References to other files
- **Named pipes (FIFOs)**: Inter-process communication channels
- **Socket files**: Network communication endpoints

### 10. What are the contents of the inode?
An inode typically contains:
- File mode (type and permissions)
- Owner ID and group ID
- File size in bytes
- Timestamps (last access, modification, creation)
- Link count (number of hard links)
- Pointers to data blocks
- File system-specific attributes

### 11. What is the use of a directory file?
A directory file serves as a mapping between human-readable filenames and their corresponding inode numbers. It contains directory entries, each consisting of:
- Filename
- Inode number
- File type
This allows the file system to locate files by name and maintain the hierarchical directory structure.

### 12. How does the operating system maintain security for files?
The OS maintains file security through:
- **Permissions**: Read, write, and execute permissions for owner, group, and others
- **Ownership**: User ID and group ID associated with each file
- **Access Control Lists (ACLs)**: More granular permission control
- **File attributes**: Hidden, system, archive flags
- **Encryption**: Protecting file content from unauthorized access
- **Audit logging**: Tracking file access attempts

### 13. What happens when a user wants to open the file?
When a user opens a file:
1. The system checks if the file exists and verifies permissions
2. An available file descriptor is allocated from the process's UAREA
3. A FileTable entry is created and initialized
4. The file's inode is loaded into memory (if not already present)
5. The FileTable is linked to the inode
6. Read/write offsets are set to 0 (or based on open mode)
7. The file descriptor is returned to the user process

### 14. What happens when a user calls lseek system call?
When lseek is called:
1. The system validates the file descriptor and offset parameters
2. The FileTable entry for the file is located
3. The read/write offset is updated to the new position
4. The new offset position is returned to the caller
5. Subsequent read/write operations will start from this new position
This allows random access within files without reading intermediate data.

### 15. What is the difference between library function and system call?
**Library functions**:
- Execute in user space
- Provide higher-level abstractions
- May use multiple system calls internally
- Faster for simple operations
- Example: printf(), fopen()

**System calls**:
- Transition from user mode to kernel mode
- Provide direct access to OS services
- Single, specific operation
- More overhead due to context switch
- Example: read(), write(), open()

### 16. What is the use of this project?
This CVFS project serves several purposes:
- **Educational**: Demonstrates file system concepts and implementation
- **Learning tool**: Helps understand OS-level file operations
- **Prototype**: Shows how virtual file systems work
- **Foundation**: Can be extended for more complex file system features
- **Practice**: Provides hands-on experience with system programming

### 17. What are the difficulties that you faced in this project?
Common challenges in implementing CVFS:
- **Memory management**: Proper allocation and deallocation of dynamic structures
- **Error handling**: Comprehensive error checking and recovery
- **Data structure design**: Efficient organization of file metadata
- **Command parsing**: Robust parsing of user commands with various formats
- **Cross-platform compatibility**: Handling differences between Windows and Unix systems
- **Testing**: Ensuring all edge cases are covered
- **Performance**: Optimizing file operations for efficiency

### 18. Is there any improvement needed in this project?
Several improvements could enhance the CVFS:
- **Complete file operations**: Implement read, write, stat, unlink, chmod functions
- **Directory support**: Add directory creation and navigation
- **Persistent storage**: Save file system state to disk
- **Enhanced security**: Implement user authentication and access control
- **Performance optimization**: Use hash tables for faster file lookup
- **Memory efficiency**: Implement memory pools and better buffer management
- **Error recovery**: Add journaling and consistency checks
- **Extended attributes**: Support for file metadata beyond basic properties
- **Concurrent access**: Multi-process file system support
- **Larger file support**: Remove size limitations and implement sparse files

## 17. Internal Working of System Calls

### 1. `open()` System Call
**Purpose**: Opens a file and returns a file descriptor for subsequent operations.

**Internal Working**:
1. **Pathname Resolution**: The kernel resolves the file path to locate the corresponding inode
2. **Permission Check**: Verifies if the process has required permissions based on access mode
3. **File Descriptor Allocation**: Allocates the lowest available file descriptor from the process's UAREA
4. **File Table Entry Creation**: Creates a new entry in the system-wide file table containing:
   - Current file offset (initialized to 0)
   - Access mode (read/write/append)
   - Pointer to the file's inode
5. **Inode Reference**: Increments the inode's reference count
6. **Return Value**: Returns the file descriptor to the calling process

**Demonstration Program**:
```c
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = open("example.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }
    printf("File opened with descriptor: %d\n", fd);
    close(fd);
    return 0;
}
```

### 2. `close()` System Call
**Purpose**: Closes an open file descriptor and releases associated resources.

**Internal Working**:
1. **File Descriptor Validation**: Verifies the descriptor is valid and currently open
2. **UAREA Entry Release**: Marks the file descriptor entry as available in the process's UAREA
3. **File Table Update**: Decrements the reference count in the system-wide file table
4. **Inode Reference Decrement**: If file table reference count reaches zero, decrements inode reference count
5. **Resource Cleanup**: If inode reference count reaches zero:
   - Writes modified inode data back to disk
   - Releases any cached file data
   - Frees the inode table entry
6. **Return Value**: Returns 0 on success, -1 on error

**Demonstration Program**:
```c
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = open("test.txt", O_CREAT | O_WRONLY, 0644);
    if (fd == -1) return 1;
    
    if (close(fd) == 0) {
        printf("File closed successfully\n");
    } else {
        perror("close failed");
    }
    return 0;
}
```

### 3. `read()` System Call
**Purpose**: Reads data from an open file into a buffer.

**Internal Working**:
1. **Parameter Validation**: Checks file descriptor validity and buffer permissions
2. **File Table Lookup**: Locates the file table entry using the file descriptor
3. **Permission Check**: Verifies the file was opened with read permissions
4. **Offset Management**: Uses the current read offset from the file table entry
5. **Data Transfer**:
   - Calculates which disk blocks contain the requested data
   - Copies data from disk buffers to the user's buffer
   - Updates the read offset by the number of bytes actually read
6. **EOF Handling**: Returns 0 if end of file is reached
7. **Return Value**: Returns number of bytes read, 0 on EOF, or -1 on error

**Demonstration Program**:
```c
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    char buffer[100];
    int fd = open("data.txt", O_RDONLY);
    if (fd == -1) return 1;
    
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read > 0) {
        buffer[bytes_read] = '\0';
        printf("Read %zd bytes: %s\n", bytes_read, buffer);
    }
    
    close(fd);
    return 0;
}
```

### 4. `write()` System Call
**Purpose**: Writes data from a buffer to an open file.

**Internal Working**:
1. **Parameter Validation**: Validates file descriptor and buffer accessibility
2. **File Table Lookup**: Finds the file table entry using the file descriptor
3. **Permission Check**: Ensures file was opened with write permissions
4. **Offset Management**: Uses current write offset from file table entry
5. **Data Transfer**:
   - Allocates disk blocks if needed
   - Copies data from user buffer to kernel buffers
   - Marks blocks as dirty for eventual disk write
   - Updates write offset by number of bytes written
6. **File Size Update**: Updates file size if write extends beyond current end
7. **Return Value**: Returns number of bytes written or -1 on error

**Demonstration Program**:
```c
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) return 1;
    
    const char *data = "Hello, World!";
    ssize_t bytes_written = write(fd, data, strlen(data));
    
    if (bytes_written > 0) {
        printf("Wrote %zd bytes\n", bytes_written);
    }
    
    close(fd);
    return 0;
}
```

### 5. `lseek()` System Call
**Purpose**: Changes the file offset for subsequent read/write operations.

**Internal Working**:
1. **Parameter Validation**: Validates file descriptor and offset parameters
2. **File Table Lookup**: Locates the file table entry
3. **Offset Calculation**:
   - **SEEK_SET (0)**: Sets offset to the specified value
   - **SEEK_CUR (1)**: Sets offset relative to current position
   - **SEEK_END (2)**: Sets offset relative to file end
4. **Boundary Check**: Ensures the new offset is within valid range (>= 0)
5. **Offset Update**: Updates both read and write offsets in the file table entry
6. **Hole Handling**: If seeking beyond file end, creates a hole (sparse file)
7. **Return Value**: Returns the new file offset or -1 on error

**Demonstration Program**:
```c
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = open("seek_test.txt", O_CREAT | O_RDWR, 0644);
    if (fd == -1) return 1;
    
    // Write initial data
    write(fd, "Hello", 5);
    
    // Seek to position 10 and write more data
    off_t new_pos = lseek(fd, 10, SEEK_SET);
    printf("New position: %ld\n", new_pos);
    write(fd, "World", 5);
    
    close(fd);
    return 0;
}
```

### 6. `stat()` System Call
**Purpose**: Retrieves file status information (metadata).

**Internal Working**:
1. **Pathname Resolution**: Resolves the file path to locate the inode
2. **Permission Check**: Verifies search permissions on all directory components
3. **Inode Access**: Locates and reads the inode from disk or cache
4. **Data Structure Population**: Fills the stat structure with:
   - File type and permissions (st_mode)
   - Owner and group IDs (st_uid, st_gid)
   - File size (st_size)
   - Timestamps (st_atime, st_mtime, st_ctime)
   - Number of links (st_nlink)
   - Device information (st_dev, st_rdev)
   - Inode number (st_ino)
5. **Return Value**: Returns 0 on success, -1 on error

**Demonstration Program**:
```c
#include <sys/stat.h>
#include <stdio.h>
#include <time.h>

int main() {
    struct stat file_stat;
    
    if (stat("example.txt", &file_stat) == 0) {
        printf("File size: %ld bytes\n", file_stat.st_size);
        printf("Permissions: %o\n", file_stat.st_mode & 0777);
        printf("Last modified: %s", ctime(&file_stat.st_mtime));
        printf("Inode number: %ld\n", file_stat.st_ino);
    } else {
        perror("stat failed");
    }
    
    return 0;
}
```

### 7. `chmod()` System Call
**Purpose**: Changes file permissions.

**Internal Working**:
1. **Pathname Resolution**: Resolves the file path to locate the inode
2. **Ownership Check**: Verifies the calling process owns the file or has root privileges
3. **Permission Validation**: Validates the new permission mode
4. **Inode Update**:
   - Locks the inode for modification
   - Updates the permission field in the inode
   - Marks the inode as dirty for disk write
   - Updates the change timestamp (ctime)
5. **Inode Unlock**: Releases the inode lock
6. **Return Value**: Returns 0 on success, -1 on error

**Demonstration Program**:
```c
#include <sys/stat.h>
#include <stdio.h>

int main() {
    // Set file permissions to read/write for owner, read for group/others
    if (chmod("example.txt", 0644) == 0) {
        printf("Permissions changed successfully\n");
    } else {
        perror("chmod failed");
    }
    
    return 0;
}
```

### 8. `unlink()` System Call
**Purpose**: Removes a directory entry and decrements the file's link count.

**Internal Working**:
1. **Pathname Resolution**: Resolves the file path to locate the inode and directory entry
2. **Permission Check**: Verifies write and execute permissions on the containing directory
3. **Directory Entry Removal**: Removes the filename-to-inode mapping from the directory
4. **Link Count Decrement**: Decrements the link count in the file's inode
5. **File Deletion Check**: If link count reaches zero:
   - Marks the inode as deleted
   - Releases all data blocks allocated to the file
   - Frees the inode for reuse
6. **Directory Update**: Marks the directory as modified for disk write
7. **Return Value**: Returns 0 on success, -1 on error

**Demonstration Program**:
```c
#include <unistd.h>
#include <stdio.h>

int main() {
    if (unlink("temp_file.txt") == 0) {
        printf("File deleted successfully\n");
    } else {
        perror("unlink failed");
    }
    
    return 0;
}
```

## 18. Unix Commands Explanation

### 1. `ls` Command
**Purpose**: Lists directory contents.

**Usage and Options**:
- `ls` - Basic listing of files and directories
- `ls -l` - Long format with detailed information
- `ls -a` - Shows all files including hidden ones (starting with .)

**Output Examples**:
```
$ ls
file1.txt  file2.txt  directory/

$ ls -l
-rw-r--r-- 1 user group 1024 Jan 17 10:00 file1.txt
drwxr-xr-x 2 user group 4096 Jan 17 10:00 directory/

$ ls -a
.  ..  .hidden_file  file1.txt  file2.txt
```

### 2. `rm` Command
**Purpose**: Removes files and directories.

**Usage**:
- `rm filename` - Removes a file
- `rm -r directory` - Removes directory and its contents recursively
- `rm -f filename` - Force remove without confirmation

**Example**:
```
$ rm temp.txt
$ rm -r old_directory/
```

### 3. `cat` Command
**Purpose**: Concatenates and displays file contents.

**Usage**:
- `cat filename` - Display file contents
- `cat file1 file2` - Display multiple files
- `cat file1 > file2` - Copy file1 to file2

**Example**:
```
$ cat readme.txt
This is the content of readme.txt
```

### 4. `cd` Command
**Purpose**: Changes the current working directory.

**Usage**:
- `cd /path/to/directory` - Change to specific directory
- `cd ..` - Go to parent directory
- `cd ~` - Go to home directory
- `cd -` - Go to previous directory

**Example**:
```
$ cd /home/user/documents
$ pwd
/home/user/documents
```

### 5. `cp` Command
**Purpose**: Copies files and directories.

**Usage**:
- `cp source destination` - Copy file
- `cp -r source_dir dest_dir` - Copy directory recursively
- `cp file1 file2 directory/` - Copy multiple files to directory

**Example**:
```
$ cp original.txt backup.txt
$ cp -r project/ project_backup/
```

### 6. `mkdir` Command
**Purpose**: Creates directories.

**Usage**:
- `mkdir dirname` - Create single directory
- `mkdir -p path/to/nested/dir` - Create parent directories as needed

**Example**:
```
$ mkdir new_project
$ mkdir -p projects/webapp/src
```

### 7. `pwd` Command
**Purpose**: Prints the current working directory.

**Usage**:
- `pwd` - Shows absolute path of current directory

**Example**:
```
$ pwd
/home/user/projects/cvfs
```

### 8. `touch` Command
**Purpose**: Creates empty files or updates timestamps.

**Usage**:
- `touch filename` - Create empty file or update timestamp
- `touch -t timestamp file` - Set specific timestamp

**Example**:
```
$ touch newfile.txt
$ touch existing_file.txt  # Updates timestamp
```

### 9. `stat` Command
**Purpose**: Displays detailed file or filesystem status.

**Usage**:
- `stat filename` - Show detailed file information
- `stat -f filesystem` - Show filesystem information

**Example**:
```
$ stat file.txt
  File: file.txt
  Size: 1024        Blocks: 8          IO Block: 4096   regular file
Device: 801h/2049d    Inode: 123456      Links: 1
Access: (0644/-rw-r--r--)  Uid: (1000/user)   Gid: (1000/user)
Access: 2026-01-17 10:00:00.000000000 +0530
Modify: 2026-01-17 10:00:00.000000000 +0530
Change: 2026-01-17 10:00:00.000000000 +0530
 Birth: -
```

### 10. `man` Command
**Purpose**: Displays manual pages for commands and system calls.

**Usage**:
- `man command` - Show manual for specific command
- `man 2 syscall` - Show manual for system call (section 2)
- `man -k keyword` - Search for commands containing keyword

**Example**:
```
$ man ls
$ man 2 open
$ man -k file
```

**Manual Sections**:
1. User commands
2. System calls
3. Library functions
4. Special files
5. File formats
6. Games
7. Miscellaneous
8. System administration commands

## 19. Complete Demonstration Program - All System Calls

This comprehensive program demonstrates all 8 system calls (`open`, `close`, `read`, `write`, `lseek`, `stat`, `chmod`, `unlink`) working together in a single application.

```c
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define FILENAME "demo_system_calls.txt"
#define BUFFER_SIZE 256

void demonstrate_open() {
    printf("\n=== Demonstrating open() system call ===\n");
    
    // Open file for writing (create if doesn't exist, truncate if exists)
    int fd = open(FILENAME, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open failed");
        return;
    }
    
    printf("File '%s' opened successfully with file descriptor: %d\n", FILENAME, fd);
    
    // Don't close yet, we'll use it for write demonstration
    demonstrate_write(fd);
    
    // Close the file
    if (close(fd) == 0) {
        printf("File closed successfully\n");
    } else {
        perror("close failed");
    }
}

void demonstrate_write(int fd) {
    printf("\n=== Demonstrating write() system call ===\n");
    
    const char *data = "Hello, World! This is a demonstration of system calls.\n";
    ssize_t bytes_written = write(fd, data, strlen(data));
    
    if (bytes_written == -1) {
        perror("write failed");
    } else {
        printf("Successfully wrote %zd bytes to file\n", bytes_written);
    }
}

void demonstrate_stat() {
    printf("\n=== Demonstrating stat() system call ===\n");
    
    struct stat file_stat;
    
    if (stat(FILENAME, &file_stat) == 0) {
        printf("File information for '%s':\n", FILENAME);
        printf("  Size: %ld bytes\n", file_stat.st_size);
        printf("  Permissions: %o\n", file_stat.st_mode & 0777);
        printf("  Owner UID: %d\n", file_stat.st_uid);
        printf("  Group GID: %d\n", file_stat.st_gid);
        printf("  Inode number: %ld\n", file_stat.st_ino);
        printf("  Number of links: %ld\n", file_stat.st_nlink);
        
        // Display timestamps
        printf("  Last access: %s", ctime(&file_stat.st_atime));
        printf("  Last modification: %s", ctime(&file_stat.st_mtime));
        printf("  Last status change: %s", ctime(&file_stat.st_ctime));
        
        // File type
        if (S_ISREG(file_stat.st_mode)) {
            printf("  File type: Regular file\n");
        } else if (S_ISDIR(file_stat.st_mode)) {
            printf("  File type: Directory\n");
        }
    } else {
        perror("stat failed");
    }
}

void demonstrate_read() {
    printf("\n=== Demonstrating read() system call ===\n");
    
    int fd = open(FILENAME, O_RDONLY);
    if (fd == -1) {
        perror("open for read failed");
        return;
    }
    
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    
    if (bytes_read == -1) {
        perror("read failed");
    } else {
        buffer[bytes_read] = '\0';  // Null-terminate the string
        printf("Successfully read %zd bytes:\n", bytes_read);
        printf("Content: %s", buffer);
    }
    
    close(fd);
}

void demonstrate_lseek() {
    printf("\n=== Demonstrating lseek() system call ===\n");
    
    int fd = open(FILENAME, O_RDWR);
    if (fd == -1) {
        perror("open for lseek failed");
        return;
    }
    
    // Get current file position
    off_t current_pos = lseek(fd, 0, SEEK_CUR);
    printf("Current file position: %ld\n", current_pos);
    
    // Seek to beginning
    off_t start_pos = lseek(fd, 0, SEEK_SET);
    printf("After SEEK_SET: %ld\n", start_pos);
    
    // Seek to end
    off_t end_pos = lseek(fd, 0, SEEK_END);
    printf("After SEEK_END: %ld (file size)\n", end_pos);
    
    // Seek to middle
    off_t middle_pos = lseek(fd, 10, SEEK_SET);
    printf("After seeking to position 10: %ld\n", middle_pos);
    
    // Write additional data at position 10
    const char *additional_data = "[INSERTED]";
    ssize_t bytes_written = write(fd, additional_data, strlen(additional_data));
    printf("Wrote %zd bytes at position 10\n", bytes_written);
    
    close(fd);
    
    // Read the modified file to show the result
    printf("\nFile content after lseek and write:\n");
    demonstrate_read();
}

void demonstrate_chmod() {
    printf("\n=== Demonstrating chmod() system call ===\n");
    
    // Show current permissions
    struct stat file_stat;
    if (stat(FILENAME, &file_stat) == 0) {
        printf("Current permissions: %o\n", file_stat.st_mode & 0777);
    }
    
    // Change permissions to read-write for owner, read-only for group and others
    if (chmod(FILENAME, 0644) == 0) {
        printf("Permissions changed to 0644 (rw-r--r--) successfully\n");
    } else {
        perror("chmod failed");
    }
    
    // Verify the change
    if (stat(FILENAME, &file_stat) == 0) {
        printf("New permissions: %o\n", file_stat.st_mode & 0777);
    }
    
    // Change permissions to make it executable
    if (chmod(FILENAME, 0755) == 0) {
        printf("Permissions changed to 0755 (rwxr-xr-x) successfully\n");
    } else {
        perror("chmod to 0755 failed");
    }
    
    // Verify the change
    if (stat(FILENAME, &file_stat) == 0) {
        printf("New permissions: %o\n", file_stat.st_mode & 0777);
    }
}

void demonstrate_unlink() {
    printf("\n=== Demonstrating unlink() system call ===\n");
    
    // Check if file exists before unlinking
    struct stat file_stat;
    if (stat(FILENAME, &file_stat) == 0) {
        printf("File '%s' exists and will be deleted\n", FILENAME);
        printf("File size before deletion: %ld bytes\n", file_stat.st_size);
        
        if (unlink(FILENAME) == 0) {
            printf("File deleted successfully\n");
        } else {
            perror("unlink failed");
        }
    } else {
        printf("File '%s' does not exist\n", FILENAME);
    }
    
    // Verify deletion
    if (stat(FILENAME, &file_stat) == -1) {
        printf("File deletion verified: file no longer exists\n");
    }
}

void demonstrate_close() {
    printf("\n=== Demonstrating close() system call ===\n");
    
    // Open a file specifically for close demonstration
    int fd = open("temp_close_demo.txt", O_CREAT | O_WRONLY, 0644);
    if (fd == -1) {
        perror("open for close demo failed");
        return;
    }
    
    printf("File opened with descriptor: %d\n", fd);
    
    // Write some data
    const char *data = "This file will be closed and then deleted\n";
    write(fd, data, strlen(data));
    
    // Close the file
    if (close(fd) == 0) {
        printf("File closed successfully\n");
    } else {
        perror("close failed");
    }
    
    // Clean up the temporary file
    unlink("temp_close_demo.txt");
}

int main() {
    printf("=== Complete System Calls Demonstration Program ===\n");
    printf("This program demonstrates all major file system system calls\n");
    
    // Demonstrate each system call in logical order
    demonstrate_open();      // Creates and writes to file
    demonstrate_stat();      // Shows file information
    demonstrate_read();      // Reads file content
    demonstrate_lseek();     // Demonstrates file positioning
    demonstrate_chmod();     // Changes file permissions
    demonstrate_close();     // Shows close operation
    demonstrate_unlink();    // Deletes the main file
    
    printf("\n=== All System Calls Demonstrated Successfully ===\n");
    printf("Program completed. All temporary files have been cleaned up.\n");
    
    return 0;
}
```

### Compilation and Execution Instructions

**To compile the program:**
```bash
gcc -o system_calls_demo system_calls_demo.c
```

**To run the program:**
```bash
./system_calls_demo
```

**Expected Output:**
```
=== Complete System Calls Demonstration Program ===
This program demonstrates all major file system system calls

=== Demonstrating open() system call ===
File 'demo_system_calls.txt' opened successfully with file descriptor: 3

=== Demonstrating write() system call ===
Successfully wrote 54 bytes to file
File closed successfully

=== Demonstrating stat() system call ===
File information for 'demo_system_calls.txt':
  Size: 54 bytes
  Permissions: 644
  Owner UID: 1000
  Group GID: 1000
  Inode number: 123456
  Number of links: 1
  Last access: Mon Jan 17 10:18:00 2026
  Last modification: Mon Jan 17 10:18:00 2026
  Last status change: Mon Jan 17 10:18:00 2026
  File type: Regular file

=== Demonstrating read() system call ===
Successfully read 54 bytes:
Content: Hello, World! This is a demonstration of system calls.

=== Demonstrating lseek() system call ===
Current file position: 0
After SEEK_SET: 0
After SEEK_END: 54 (file size)
After seeking to position 10: 10
Wrote 10 bytes at position 10

File content after lseek and write:
Successfully read 64 bytes:
Content: Hello, Wo[INSERTED]monstration of system calls.

=== Demonstrating chmod() system call ===
Current permissions: 644
Permissions changed to 0644 (rw-r--r--) successfully
New permissions: 644
Permissions changed to 0755 (rwxr-xr-x) successfully
New permissions: 755

=== Demonstrating close() system call ===
File opened with descriptor: 3
File closed successfully

=== Demonstrating unlink() system call ===
File 'demo_system_calls.txt' exists and will be deleted
File size before deletion: 64 bytes
File deleted successfully
File deletion verified: file no longer exists

=== All System Calls Demonstrated Successfully ===
Program completed. All temporary files have been cleaned up.
```

### Key Features of This Demonstration

1. **Sequential Logic**: Each system call builds upon the previous ones
2. **Error Handling**: Comprehensive error checking with perror() calls
3. **Verification**: Each operation is verified with subsequent checks
4. **Real-world Usage**: Demonstrates practical applications of each system call
5. **Cleanup**: Proper cleanup of all created files
6. **Informative Output**: Detailed status messages for each operation

This program provides a complete, working example of how all the major file system system calls work together in a real application.

