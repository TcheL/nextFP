#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOFATALERR 0
#define FAIL2CHECK 1
#define LENSTR 128

#define ISEQSTR(a,b) ( ! strcmp(a, b))

int nseek = 1;
bool isfore = true, isintr = false;
void print_help_info(const int, const char *);
void fconv_print(const char *);
void dconv_print(const char *);

int main(int argc, char *argv[])
{
  int i, isn, len;
  char strcmd[LENSTR], strval[LENSTR];

  if(argc < 2)
    isintr = true;
  else
    {
      i = 0;
      while(1)
      {
        i++;
        if(argv[i][0] == '-')
          if(ISEQSTR(argv[i], "-h") || ISEQSTR(argv[i], "--help"))
            print_help_info(NOFATALERR, "NULL");
          else if(ISEQSTR(argv[i], "-i"))
            isintr = true;
          else if(ISEQSTR(argv[i], "-f"))
            isfore = true;
          else if(ISEQSTR(argv[i], "-b"))
            isfore = false;
          else if(argv[i][1] == 'n')
          {
            strcpy(strval, argv[i]);
            sscanf(strval, "%*2s%d", &nseek);
          }
          else
          {
            char strerr[LENSTR];
            sprintf(strerr, "Encounter with an invalid "
              "command line argument <%s>", argv[i]);
            print_help_info(FAIL2CHECK, strerr);
          }
        else
        {
          isn = i;
          break;
        }

        if(i == argc - 1)
        {
          isintr = true;
          break;
        }
      }
    }


  if(isintr)
  {
    printf("Enter the interactive mode:\n");
    while(1)
    {
      printf(">> ");
      fgets(strcmd, LENSTR, stdin);
      sscanf(strcmd, "%s", strval);
      if(ISEQSTR(strval, "q") || ISEQSTR(strval, "quit"))
        break;
      else
      {
        len = strlen(strval);
        if(strval[len - 1] == 'F' || strval[len - 1] == 'f')
          fconv_print(strval);
        else if(strval[len - 1] == 'L' || strval[len - 1] == 'l')
          dconv_print(strval);
        else
          printf("<< Warning: End number with 'F' or 'L', please.\n");
      }
    }
  }
  else
    for(int i = isn; i < argc; i++)
    {
      len = strlen(argv[i]);
      if(argv[i][len - 1] == 'F' || argv[i][len - 1] == 'f')
        fconv_print(argv[i]);
      else if(argv[i][len - 1] == 'L' || argv[i][len - 1] == 'l')
        dconv_print(argv[i]);
      else
        printf("<< Warning: Ignore the number "
          "without ending with 'F' or 'L'.\n");
    }

  return 0;
}

void print_help_info(const int exitcode, const char *errinfo)
{
  if(exitcode) printf("Error: %s.\n", errinfo);
  printf("\nUsage:\n");
  printf("  nextFP [ -i ] [ -f | -b ] [ -nNUM ] [ fpn1 fpn2 ... ]\n");
  printf("    -i: interactive mode where the anchor point list "
    "is not needed.\n");
  printf("    -f: seek forward the next floating-point number.\n");
  printf("    -b: seek backward the next floating-point number.\n");
  printf("    -nNUM: seek the next $NUM floating-point number.\n");
  printf("    fpn1 fpn2 ... : the anchor point list "
    "of floating-point number.\n");
  printf("\n");
  exit(exitcode);
}

void fconv_print(const char *strval)
{
  int fout;
  float fin;
  sscanf(strval, "%f", &fin);
  printf("<< %27.18f |", fin);
  for(int i = 1; i <= nseek; i++)
  {
    if(isfore)
      fout = (int&)fin + i;
    else
      fout = (int&)fin - i;
    printf(" %27.18f", (float&)fout);
  }
  printf("\n");
}

void dconv_print(const char *strval)
{
  long int dout;
  double din;
  sscanf(strval, "%lf", &din);
  printf("<< %27.18f |", din);
  for(int i = 1; i <= nseek; i++)
  {
    if(isfore)
      dout = (long int&)din + i;
    else
      dout = (long int&)din - i;
    printf(" %27.18f", (double&)dout);
  }
  printf("\n");
}
