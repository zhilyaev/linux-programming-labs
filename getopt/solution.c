#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>


int main (int argc, char* argv[])
{
  extern int opterr;
  opterr = 0;

  const char* query = NULL;

  /* A string listing valid short options letters.  */
  const char* const short_options = "q:iv";
  /* An array describing valid long options.  */
  const struct option long_options[] = {
    { "query",     required_argument, NULL, 'q' },
    { "longinformationrequest",   no_argument, NULL, 'i' },
    { "version",  no_argument, NULL, 'v' },
    { NULL,       0, NULL, 0   }   /* Required at end of array.  */
  };


  char correct = '+';
  int next_option;
  while (next_option != -1){
      next_option = getopt_long (argc, argv, short_options, long_options, NULL);
      // printf("option=%c\n", next_option);
      switch (next_option){
      case 'q':
          query = optarg;
          // printf("q=%s\n", query);
      case 'i':
      case 'v':
      case -1:
          break;
      default:    /* Something else: unexpected.  */
        correct = '-';
        break;
      }
  }

  printf("%c\n", correct);

  return 0;
}