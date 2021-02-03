// Programming Project 5 - Archipelago Expedition Planning
// Author: Mohammed Hisham Moizuddin - CS211 FALL 2020
// UIN - 650344339

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include "island.h"

class ArchipelagoExpedition
{
  private:
	  // Create the Data Members for the Archipelago Network here
	  Island * islandList;
	  int size;
	  ListString fileList;

  public:

	  // Use a constructor to initialize the Data Members for your expedition
	ArchipelagoExpedition()
	{ islandList = new Island[11];
		size = 10; }

	~ArchipelagoExpedition()
	{ 
    for (int i=0; i<=size; i++)
		{ islandList[i].clear(); }

		delete[] islandList;
	}

	// The main loop for reading in input
	void processCommandLoop(FILE * inFile)
	{
		char buffer[300];
		char * input;

		input = fgets(buffer, 300, inFile); // get a line of input

		// loop until all lines are read from the input
		while (input != NULL)
		{
			// process each line of input using the strtok functions
			char * command;
			command = strtok(input, " \r\n\t");

			printf("*%s*\n", command);

			if (command == NULL)
				printf("Blank Line\n");

			else if (strcmp(command, "q") == 0)
			{ for (int i=0; i<=size; i++)
				{
					islandList[i].clear();
				}
				delete[] islandList;
				exit(1); }

			else if (strcmp(command, "?") == 0)
				showCommands();

			else if (strcmp(command, "t") == 0)
				doTravel();

			else if (strcmp(command, "r") == 0)
				doResize();

			else if (strcmp(command, "i") == 0)
				doInsert();

			else if (strcmp(command, "d") == 0)
				doDelete();

			else if (strcmp(command, "l") == 0)
				doList();

			else if (strcmp(command, "f") == 0)
				doFile();

			else if (strcmp(command, "#") == 0)
				;

			else
				printf("Command is not known: %s\n", command);

			input = fgets(buffer, 300, inFile); // get the next line of input
		}
	}

	void showCommands()
	{
		printf("The commands for this project are:\n");
		printf("  q \n");
		printf("  ? \n");
		printf("  # \n");
		printf("  t <int1> <int2> \n");
		printf("  r <int> \n");
		printf("  i <int1> <int2> \n");
		printf("  d <int1> <int2> \n");
		printf("  l \n");
		printf("  f <filename> \n");
	}

	bool dfs(int a, int b)
	{
		Node * tmp = islandList[a].getNode();

		while (tmp!=nullptr)
		{
			int c = tmp-> getValue();

			if (c==b)
			{ return true; }

			if (!islandList[c].isIslandVisited())
			{
				islandList[c].visitIsland();
				if (dfs(c, b))
				{ return true; }
			}

			tmp = tmp->getNext();
		}
		return false;
	}

	void depthFirstSearchHelper(int x, int y)
	{
		for (int i=1; i<=size; i++)
		{ islandList[i].unvisitIsland(); }

		if (dfs(x, y))
		{ cout << "You can get from island "<<x <<" to island "<<y <<" in one or more ferry rides"<<endl; }

		else
		{ cout << "You can NOT get from island "<<x <<" to island " <<y << " in one or more ferry rides" <<endl; }
	}

	void doTravel()
	{
		int val1 = 0;
		int val2 = 0;

		// get an integer value from the input
		char * next = strtok(NULL, " \n\t");

		if (next == NULL)
		{ printf("Integer value expected\n");
			return; }

		val1 = atoi(next);

		if (val1 == 0 && strcmp(next, "0") != 0)
		{ printf("Integer value expected\n");
			return; }

		if (val1 > size || val1 < 1)
		{ cout << "Invalid value for island" << endl;
			return; }

		// get another integer value from the input
		next = strtok(NULL, " \n\t");

		if (next == NULL)
		{ printf("Integer value expected\n");
			return; }

		val2 = atoi(next);

		if (val2 == 0 && strcmp(next, "0") != 0)
		{ printf("Integer value expected\n");
			return; }

		if (val2 >size || val2< 1)
		{ cout << "Invalid value for island" << endl;
			return; }

		printf("Performing the Travel Command from %d to %d\n", val1, val2);
		depthFirstSearchHelper(val1, val2);
	}

	void doResize()
	{
		int val1 = 0;
		char * next = strtok(NULL, " \n\t");

		if (next == NULL)
		{ printf("Integer value expected\n");
			return; }

		val1 = atoi(next);

		if (val1 == 0 && strcmp(next, "0") != 0)
		{ printf("Integer value expected\n");
			return; }

		printf("Performing the Resize Command with %d\n", val1);

		for (int i=0; i<size; i++)
		{ islandList[i].clear(); }

		delete[] islandList;
		islandList = new Island[val1 + 1];
		size = val1;
	}

	void doInsert()
	{
		int val1 = 0;
		int val2 = 0;

		char * next = strtok(NULL, " \n\t");

		if (next == NULL)
		{ printf("Integer value expected\n");
			return; }
		val1 = atoi(next);
    
		if ((val1 == 0 && strcmp(next, "0") != 0))
		{ printf("Integer value expected\n");
			return; }
		if (val1 > size || val1 < 1)
		{ cout << "Invalid value for island" <<endl;
			return; }
		next = strtok(NULL, " \n\t");

		if (next == NULL)
		{ printf("Integer value expected\n");
			return; }

		val2 = atoi(next);
		if ((val2 == 0 && strcmp(next, "0") != 0))
		{
			printf("Integer value expected\n");
			return;
		}
		if (val2 >size || val2 < 1)
		{
			cout << "Invalid value for island" << endl;
			return;
		}
		cout << "Performing the Insert Command for " << val1 << endl;
		islandList[val1].insertValue(val2);
	}

	void doDelete()
	{
		int val1, val2;
		val1 = val2 = 0;

		char * next = strtok(NULL, " \n\t");

		if (next == NULL)
		{ printf("Integer value expected\n");
			return; }

		val1 = atoi(next);

		if ((val1 == 0 && strcmp(next, "0") != 0))
		{ printf("Integer value expected\n");
			return; }

		if (val1 >size || val1< 1)
		{ cout << "Invalid value for island" << endl;
			return; }

		next = strtok(NULL, " \n\t");

		if (next == NULL)
		{ printf("Integer value expected\n");
			return; }

		val2 = atoi(next);

		if ((val2 == 0 && strcmp(next, "0") != 0))
		{ printf("Integer value expected\n");
			return; }
		if (val2 > size || val2 < 1)
		{ cout <<"Invalid value for island"<<endl;
			return; }

		if (!islandList[val1].doesValueExist(val2))
		{ cout <<"Ferry ride does not exist"<<endl;
			return; }

		cout << "Performing the Delete Command for " <<val1 <<endl;
		islandList[val1].removeValue(val2);
	}

	void doList()
	{
		cout << "Displaying the adjacency list:" << endl;

		for (int i=1; i<=size; i++)
		{ cout <<i <<" --> ";
			Node * node = islandList[i].getNode();

			while (node!=nullptr)
			{ cout << " " << node->getValue() << " ";
				node = node->getNext(); }
			cout << endl;
		}
	}

	void doFile()
	{
		// get a filename from the input
		char * fname = strtok(NULL, " \r\n\t");
		if (fname == NULL)
		{ printf("Filename expected\n");
			return; }

		FILE * inFile = fopen(fname, "r");

		if (inFile == NULL)
		{ cout <<"Cannot open the file"<< endl;
			return; }
		printf("Performing the File command with file: %s\n", fname);

		if (fileList.doesFnameExist(fname))
		{ cout <<"File is already in use"<< endl;
			return; }

		fileList.insertFname(fname);
		processCommandLoop(inFile);
		fclose(inFile);
		fileList.removeFname(fname);
	}
};


int main(int argc, char **argv)
{
	// set up the varqiable inFile to read from standard input
	FILE * inFile = stdin;

	// set up the data needed for the island adjcency list
	ArchipelagoExpedition islandData;

	// call the method that reads and parses the input
	islandData.showCommands();

	printf("\nEnter commands at blank line\n");
	printf("    (No prompts are given because of f command)\n");
	islandData.processCommandLoop(inFile);
	printf("Goodbye\n");
	return 1;
}
