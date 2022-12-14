#include <sys/types.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 

#if 0 /* recommand */ 
#define def_readlink_start_buffer     (256) 
#define def_readlink_expansion_buffer (8) 
#else /* for test */ 
#define def_readlink_start_buffer     (1) 
#define def_readlink_expansion_buffer (1) 
#endif 


char *mz_readlink(const char *s_path) 
{ 
 char *s_result; 
 size_t s_buffer_size = (size_t)(def_readlink_start_buffer); /* start buffer */ 
 int s_replace_bytes; 
 do 
 { 
  s_result = (char *)malloc(s_buffer_size); 
  if(s_result == ((char *)0))break; /* error */ 
  s_replace_bytes = readlink(s_path, s_result, s_buffer_size); 
  if(s_replace_bytes == (-1)) 
  { /* error */ 
   free(s_result); 
   s_result = (char *)0; 
   break; 
  } 
  if(s_replace_bytes < ((int)s_buffer_size)) 
  { 
   s_result[s_replace_bytes] = '\0'; 
   break; /* ok */ 
  } 
  free((void *)s_result); 
  (void)fprintf(stdout, "buffer replace %d -> %d\n", (int)s_buffer_size, ((int)s_buffer_size) + def_readlink_expansion_buffer); 
  s_buffer_size += def_readlink_expansion_buffer; 
 }while(1); 
 return(s_result); 
} 

int main(int s_argc, char **s_argv) 
{ 
 char *s_linkpath; 
 if(s_argc >= 2) 
 { 
  s_linkpath = mz_readlink(s_argv[1]); 
  if(s_linkpath != ((char *)0)) 
  { 
   (void)fprintf(stdout, "%s -> %s (%d character)\n", s_argv[1], s_linkpath, strlen(s_linkpath)); 
   free(s_linkpath); 
  } 
  else (void)fprintf(stdout, "can not readlink ! (\"%s\")\n", s_argv[1]); 
 } 
 else (void)fprintf(stdout, "usage: %s <link>\nexample: %s /proc/self/exe\n", s_argv[0], s_argv[0]); 
 return(0); 
} 
