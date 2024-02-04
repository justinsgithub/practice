#define NAME_MAX 14 /* longest filename component; */
/* system-dependent */
typedef struct {           /* portable directory entry: */
  long ino;                /* inode number */
  char name[NAME_MAX + 1]; /* name + '\0' terminator */
} Dirent;
typedef struct { /* minimal DIR: no buffering, etc. */
  int fd;        /* file descriptor for directory */
  Dirent d;      /* the directory entry */
} DIR;
DIR *opendir(char *dirname);
Dirent *readdir(DIR *dfd);
void closedir(DIR *dfd);
#define S_IFMT 0160000  /* type of file: */
#define S_IFDIR 0040000 /* directory */
#define S_IFCHR 0020000 /* character special */
#define S_IFBLK 0060000 /* block special */
#define S_IFREG 0100000 /* regular */
