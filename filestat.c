#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

void convert_size(long size){
  long kb = size/1024;
  long mb = kb/1024;
  long gb = mb/1024;

  printf("file size: %ld gb %ld mb %ld kb %ld b\n", gb, mb % 1024, kb % 1024, size % 1024);
}

void convert_permissions(mode_t perm){
  int grp = perm / 8;
  int usr = grp / 8;
  printf("%d %d %d\n", usr % 8, grp % 8, perm % 8);
  
}

void file_stat(char * name){
  struct stat sb;
  stat(name, &sb);

  convert_size(sb.st_size);
  convert_permissions(sb.st_mode);
  printf("last access: %s\n", ctime(&(sb.st_atime)));
}

int main(){
  file_stat("foo");
  
  return 0;
}
