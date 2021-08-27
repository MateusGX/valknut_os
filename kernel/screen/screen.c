#include "screen.h"
#include "../io/io.h"

char *const getVGA()
{
  static char *const VGA_MEMORY = (char *)0xb8000;
  return VGA_MEMORY;
}

void init_screen()
{
  unsigned int content = 25 * 160;

  while (content > 0)
  {
    getVGA()[content] = 0;
    getVGA()[content - 1] = 0x10;
    content -= 2;
  }
  char *title = "VALKNUT_OS";
  char *msg = "by Mateus A. Martins";
  _print("            @@@        @@@            ", 0x17, 2 * (( 1 * 80) + 21));
  _print("           @@@@@      @@@@@           ", 0x17, 2 * (( 2 * 80) + 21));
  _print("          @@@@@@@    @@@@@@@          ", 0x17, 2 * (( 3 * 80) + 21));
  _print("         @@@   @@@  @@@   @@@         ", 0x17, 2 * (( 4 * 80) + 21));
  _print("        @@@     @@@        @@@        ", 0x17, 2 * (( 5 * 80) + 21));
  _print("       @@@       @@@        @@@       ", 0x17, 2 * (( 6 * 80) + 21));
  _print("      @@@         @@@        @@@      ", 0x17, 2 * (( 7 * 80) + 21));
  _print("     @@@      @@@  @@@        @@@     ", 0x17, 2 * (( 8 * 80) + 21));
  _print("    @@@      @@@    @@@        @@@    ", 0x17, 2 * (( 9 * 80) + 21));
  _print("   @@@      @@@      @@@        @@@   ", 0x17, 2 * ((10 * 80) + 21));
  _print("  @@@      @@@                   @@@  ", 0x17, 2 * ((11 * 80) + 21));
  _print(" @@@@@@@  @@@    @@@@@@@@@@@@@@@@@@@@ ", 0x17, 2 * ((12 * 80) + 21));
  _print("@@@@@@@  @@@     @@@@@@@@@@@@@@@@@@@@@", 0x17, 2 * ((13 * 80) + 21));
  _print("        @@@                 @@@       ", 0x17, 2 * ((14 * 80) + 21));
  _print("       @@@                   @@@      ", 0x17, 2 * ((15 * 80) + 21));
  _print("      @@@@@@@@@@@@@@@@@@@@@@@@@@@     ", 0x17, 2 * ((16 * 80) + 21));
  _print("     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@    ", 0x17, 2 * ((17 * 80) + 21));
  _print(title, 0x1f, 2 * ((19 * 80) + 35));
  _print(msg, 0x17, 2 * ((21 * 80) + 30));
}

int isedge(int position)
{
  int height = 0;
  int result = 0;
  while (height < 25)
  {
    if (position == (height * 80))
    {
      result = 1;
      break;
    }
    height++;
  }
  return result;
}