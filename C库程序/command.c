#include "stdio.h"
#include "string.h"
void quit_command(void);
void help_command(void);
void run_command(void);
void time_command(void);
struct command{
	unsigned char * name ;
	void (*function)(void);
};
#define COMMAND(NAME) {NAME##_command}
struct command commands[] = {
  COMMAND((unsigned char *)quit),
  COMMAND(help),
  COMMAND(run),
  COMMAND(time),
};
main()
{
	unsigned char buf[6];
	memcpy(buf,commands[0].name,4);
	if(memcmp(buf,"quit",4) == 0)
	{
		commands[0].function();	
	}
	commands[1].function();
	commands[2].function();
	commands[3].function();
}
void quit_command()
{
	printf("this is quit_command printf\n");
}
void help_command()
{
	printf("this is help_command printf\n");
}
void run_command()
{
	printf("this is run_command printf\n");
}
void time_command()
{
	printf("this is time_command printf\n");
}
