#include <stdio.h>
#include <string.h>

#include "../include/parser.h"

void parseTokens(Token tokens[], int total, ParsedCommand *cmd)
{
    cmd->argCount = 0;

    for(int i=0; i<total; i++)
    {
        if(tokens[i].type == TOKEN_COMMAND)
        {
            strcpy(cmd->command, tokens[i].value);
        }

        else if(tokens[i].type == TOKEN_ARGUMENT)
        {
            strcpy(cmd->arguments[cmd->argCount], tokens[i].value);
            cmd->argCount++;
        }
    }
}

void displayParsedCommand(ParsedCommand cmd)
{
    printf("\n======= PARSED COMMAND =======\n");

    printf("Command   : %s\n", cmd.command);

    printf("Arguments : ");

    if(cmd.argCount == 0)
    {
        printf("None");
    }
    else
    {
        for(int i=0; i<cmd.argCount; i++)
        {
            printf("%s ", cmd.arguments[i]);
        }
    }

    printf("\n==============================\n");
}
