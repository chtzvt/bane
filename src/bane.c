/* Banepost.c, Version 3.0
 * Copyright (c) 2015-2017 Charlton Trezevant
 * Batman characters and dialogue are property of their respective owners.
 * License: MIT
 * Enjoy!
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// The width of the Bane ASCII art, used for padding computations in pad().
const int ART_WIDTH = 80;
// Our array of quotes.
char * uuuu[] = {
    "You're a big guy.", "He didn't fly so good!", "...for you.", "Tell me about Bane! Why does he wear the mask\?",
    "The flight plan I just filed with the agency lists me, my men, Dr.Pavel here, but only ONE of YOU!", "Dr.Pavel, I'm CIA.", "The masked man 0_0",
    "Nobody cared who I was 'til I put on the mask.", "If I pull that thing off, will you die\?", "Crashing this plane, with no survivors!",
    "Was getting caught part of your plan\?", "He wasn't alone.", "You don't get to bring friends.", "Speak of the devil and he shall appear.",
    "Get 'em on board - I'll call it in.", "FIRST ONE TO TALK GETS TO STAY ON MY AIRCRAFT.", "HE DIDN'T FLY SO GOOD! WHO WANTS TO TRY NEXT\?!",
    "Lot of loyalty for a hired gun!", "Perhaps he's wondering why someone would shoot a man before throwing him out of a plane.",
    "Wiseguy, huh\? Well at least you can talk.", "Who are you\?", "It doesn't matter who we are. What matters is our plan.", "It would be extremely painful...",
    "The fire rises!", "They expect one of us in the wreckage, brother.", "Now is not the time for fear... That comes later.", "Have we started a fire\?",
    "Well, congratulations, you got yourself caught!","What's the next step in your master plan\?"
};

// Quote selector and string padding prototypes.
char* getQuote(void);
int getPadding(char * quote);

int main(void) {

  // Retrieve a quote and the amount of padding needed to center it below our art.
  char* quote = getQuote();
  int padding = getPadding(quote);

  //Print the ASCII art and the quote :^)
  printf(
  "\n.........................,::,,,~~+==+++=+++=====................................\n"
  ".......................:.,:~~:::,:~~~~~++++=~==~I,..............................\n"
  "......................,,~7I\?III:=::~=~~~=++~:~,:~II~............................\n"
  "......................=77III\?\?III~,,~=~=++++==+=~IIII,..........................\n"
  "....................=IIIIIIIII7II\?~,~:=~===+==:::IIIIII.........................\n"
  "...................77IIIIIII\?\?\?7III~:~=~=+====~~~\?IIIIII........................\n"
  "..................IIIII\?\?+II7\?\?\?I\?\?I~::=======:::=IIIIIII,......................\n"
  ".................III\?\?I\?\?\?\?\?I\?\?\?\?=\?II=,=::~:::::::IIIIIIII,.....................\n"
  "................:\?\?\?\?II\?\?+\?+++\?+=\?+\?I\?.,:::~:~:~::\?IIIIIIII.....................\n"
  "................\?I\?\?\?\?I\?\?\?+IIIII+III77:,::~:,~~~::+\?\?IIIIIII....................\n"
  "................\?+\?\?\?I\?\?\?++\?\?I\?I\?\?7I77I=,.,,,..~:.=\?I\?IIIIII,...................\n"
  "................I\?+\?\?\?I\?\?+++\?\?\?I\?II7I\?7+=~::~=~=~=+I\?\?\?\?\?\?II\?:..................\n"
  "...............=\?+\?\?\?\?\?\?\?\?\?\?\?IIIII\?\?+\?II~:,~~~:=~\?+I7IIIIIII7I7II,..............\n"
  "..............:+\?\?+\?\?\?\?\?\?\?\?\?\?II7777777\?\?7~.~=::,,=I7I\?+===\?III7777 7I\?=\?~.......\n"
  "............,+I++\?+I\?I\?\?I\?\?\?\?IIII\?\?I7777+~,=~~+++\?7::,:~=+=\?7I\?\?I\?77777I+\?,.....\n"
  ".........:\?7II+++\?\?\?\?\?\?\?\?\?\?\?\?\?\?+~::,~~::~~=++\?:~~I=:,,,,:~+=I7~~====II\?777 7\?,..\n"
  ".....+I77777I+==+\?\?I\?\?\?I\?\?\?I+~~~===~~:,,::=+\?\?=~\?\?:~~:~~,,:~+7+~~=+=\?\?\?\?\?I7I777 \n"
  "..,+I7\?I+\?\?I\?+::=+\?I\?\?\?\?I\?\?+~~~:,~:,:,~,~~:~~::::~=~====\?I=~=\?\?~====+\?+++==++I77\n"
  "I7I7II\?+===~=:..+=\?I\?I\?\?\?\?\?+=:::=\?====~~==~==+==++=+++++I77\?\?\?I:~=~=++===\?\?+\?++=\n"
  "777\?\?+===~~:~:~=,=\?\?\?\?\?\?I\?\?\?+=+\?++==~=++\?~====++=++===+=I7IIIII~~~=+=++==\?=+++++\n"
  "77I+I\?++===~:=+I7:I\?I\?\?\?\?\?IIIII\?III\?\?I7~\?==+\?:~,::~+=,.,,77I\?II~:~~~=\?+++\?\?+\?\?\?+\n"
  "7IIII+\?\?=+==~:,7..~I\?\?\?\?\?\?\?I777777I77~:~+.:..,\?77:= 7:77., I\?I\?~:~~==\?++++=++I\?\?\n"
  "III+=+==\?++=~~,.:~=:~+++\?II\?\?I7I77II=\?...,:77=:77+. I++\?7I77II7::::~~===+\?+=+\?\?\?\n"
  "\?\?I\?I+\?++\?===~:,::~=.:~+\?\?\?\?\?III77I+\?7:,+++7I.:I7+.7II,+7~++7I:~~~~~~~=++++I+\?=+\n"
  "II=+\?\?++\?=+=~~~,:~~:~\?,,=+\?=\?\?\?III+I7+\?+,.=77.,\?77.+\? .+I7=+\?I,+~~===~==\?++\?\?+++\n"
  "\?III\?III\?\?+=~~:,:~~~:::+..,~+\?++++=7I+++..:77..:I\?..\?\?.~==+++7\?=~~~~~~===+++++=+\n"
  "7IIIII++\?+++~::,:~~~~~:::~:,.,~~==+7+\?\?+..:\?I=.+I=.,=+.~~~~=+I7,::~~~==++=++++\?\?\n"
  "I\?\?+\?I+\?\?+=+=:,:::~=++=:~::,,~,.,,77=\?\?,..,:~~:~~=,~\?I:~:=.++\?I7~~:~++=====++++\?\n"
  "I\?\?7\?++\?=++=~,:,,:~~\?\?\?\?\?+~:::,,,+7.=I\?...:.~~~,+=..:,,+,,==\?\?I,7~======+++=++++\n"
  "\?IIIIII\?\?\?++~::::,:~++\?\?\?\?==++:::7 .+7\?+,....~:~:....:~\?+~+++=..~=~~~==++=++=+++\n"
  "II\?\?\?\?\?\?\?I++=~::,+,~~+\?\?\?\?==77+.~7:.+\?II\?I~:===.~~:,~~.=I7\?.\?.+,==~~~~~~+=+\?\?++\?\n"
  "IIII\?I\?++\?++=~::~~.:~~==\?\?\?=7777II...,+\?~~:I7I:.\?\?=:77+.=777+::,=~~~~=~~++++=++\?\n"
  "I+\?I\?I=I\?++++=~::::,:~~~==+++777\?.I+.,,..., 77..+I=.=77~,,\?\?7,+:++==~~~+===+=+++\n"
  "\?\?==I\?+++\?+++=~::::,,,~~~~:~=~,\?I,,=:.,=,,I7I:..777.,77 :=~+\?I==+++=~=~~====+\?\?+\n"
  "7I77I7II\?++====::::,,:,,~~~::::=..~.,.~~:,\?\?I...7 7,.\?77:+.+I7:~===+===~++++\?+++\n"
  "I77\?+III\?++\?++=:::::,,,=:.~:::,,,:::,.~+\?,\?+\?,,,\?\?+:,+77~+,\?II7+==~~==~=~++==+\?=\n"
  "III\?II\?+++=+==++:::::,:+\?\?=.,::,:::,:+77==II\?:~,II~:,:I7,..\?I++7\?~==~=~~~:~~~=\?\?\n"
  "7I=I\?++\?\?===+++~:::~::,=\?III+..,,,,,,77\?:.7I\?,:.,,:+=.,,:.++I+\?\?+===++=~::+:~=++\n"
  "I\?\?\?\?++\?\?+=\?+=+:::::::,~\?\?I\?\?\?+:,.,:77+.,.I\?++,~,,:~~,.~~~.\?.\?I\?++++==~==~=~~:\?+\n"
  "777+II\?+\?=\?++=+=:::::::=+\?\?\?\?\?+++~:~+\?,..,~++,,::::::::,,~+++\?\?~:..,,..,~~===+~=\n"
  "\?7I=====+\?\?I\?++=::~:::==++\?\?++++++=+\?\?,..:~,:,:,,,:,,,,,.,=II+,.,,++::,...,77777\n"
  " 77I====+7I++7+\?::,:~===++\?+++\?\?+++++~~~=,,,,.,,,:::=++++\?\?\?I\?+:.,.:~:~:,..77777\n"
  "+=I\?+++\?\?\?\?+=~+~:::~=++++=+++\?\?\?\?\?\?+\?=====~~======++++++\?\?\?\?I\?=~,,,.,...,,.\?7777\n"
  "%*s%s\n\n", padding, "", quote);
}

// This function will return a random quote.
char* getQuote(void){
  //Seed random number generator with our process ID (better than using current time)
  srand(getpid());
  //Size computation for quote array (used for random selection later)
  const size_t uuuu_sz = sizeof(uuuu) / sizeof(uuuu[0]);
  // Return a quote from uuuu, located at a randomly generated index (e.g. a random quote)
  return uuuu[rand() % uuuu_sz];
}

// getPadding will attempt to center quotes beneath our ASCII art the best it can.
int getPadding(char * quote){
  int quote_len = strlen(quote);

  // If it's a really long quote, console will wrap so we shouldn't try to pad.
  if(quote_len > ART_WIDTH)
    return 0;

  // Centering doesn't have to be 100% perfect, so int math rounding is OK here.
  return (ART_WIDTH - quote_len)/2;
}
