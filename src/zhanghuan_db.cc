#include <iostream>
#include "../include/bplustree.h"
#include <fstream>

using namespace bpt;

const char* dbFileName = "./data/db.bin";
const char* nextLineHeader = "> ";
const char* exitMessage = "> bye!\n";
const char* errorMessage = "invalid input!\n";

// function prototypes
void printHelpMessage();
void selectCommand();
int insertRecord(bplus_tree* treePtr, int* index, value_t* values);
int deleteRecord(bplus_tree* duck_db_ptr,int* keyIndex);

bplus_tree* zhanghuan_db_ptr;


// initial
void initialSystem() {
  // step 1: print help message
  printHelpMessage();

  // step 2: init database from file
  // use a b+ tree, if u do not know b+ tree
  // google that first
  bplus_tree zhanghuan_db(dbFileName, (!is_file_exist(dbFileName)));
  zhanghuan_db_ptr = &zhanghuan_db;


  // TODO
  // step 3: interact with command line 
  // insert, delete, update, search
  selectCommand();  
  
}

// print help message
void printHelpMess(){
  std::cout << "*********************************************************************************************"<<endl<<endl
  <<" 				Welcome to the zhanghuan_db\n 				db file locates in \"./data/db.bin\" \n 				Author: enpei\n 				www.enpeizhao.com\n 				2018-08-31"<<endl<<endl
  <<"*********************************************************************************************" << std::endl
  <<"  .help 							print help message;" << std::endl
  <<"  .exit 							exit program;" << std::endl
  <<"  .reset 							delete db file;" << std::endl
  <<"  insert db {index} {name} {age} {email}; 			insert record;" << std::endl
  <<"  delete from db where id ={index}; 				delete record;" << std::endl
  <<"  update db {name} {age} {email} where id={index}; 		update a record;" << std::endl
  <<"  select * from db where id={index}; 				search a record by index;" << std::endl
  <<"  select * from db where id in({minIndex},{maxIndex}); 		search records between indexs;" << std::endl
  <<"*********************************************************************************************" << std::endl
  << std::endl << nextLineHeader;
}

void selectCommand() {
  char* userCommand = new char[256];
  
  while (true) {
	std::cin.getline(userCommand, 256);
	if (strcmp(userCommand, ".help") == 0) {
	  printHelpMess();
	} else if (strcmp(userCommand, ".exit") == 0) {
	  std::cout << exitMessage; 
	} else if (strcmp(userCommand, ".reset") == 0) {
	  if (remove(dbFileName) != 0) {  // can not delete 
		std::cout << "can`t delete file" << nextLineHeader;
	  } else {   // successfully delete
		std::cout << "db file has been successfully deleted" << std::endl;
		initialSystem();
	  }
	} else if (strncmp(userCommand, "insert", 6) == 0) {
	  int* keyIndex = new int;
	  value_t* insertDate = new value_t;
	  int okNum = sscanf(userCommand,"insert db %d %s %d %s;", 
	    		keyIndex, insertData->name,&(insertData->age),insertData->email);
	  if (okNum < 3) {
		  std::cout << errorMessage << nextLineHeader;
	  } else {  // get data successfully
		startTime = clock();
		int returncode = insertRecord(zhanghuan_db_ptr, keyIndex, insertData);
		finishTime = clock();

		if (returncode == 0) {  // insert successfully 
			std::cout << "> Insert uccessfully! Executed insert index:"<<   *keyIndex << ", time : "<< durationTime(&finishTime,&startTime) <<" seconds\n"<< nextLineHeader;
		} else if (returncode == 1) {  // key duplicated
			std::cout << "> failed: already exist index:"<<   *keyIndex << "\n"<< nextLineHeader;
		} else {
		  std::cout << "> failed!\n"<< nextLineHeader;
		}
	  }


	} else if (strncmp(userCommand, "delete", 6) == 0) {
	  int* keyIndex = new int;

	  int okNum = sscanf(userCommand,"delete from db where id=%d;", keyIndex);

	  if(okNum < 1){
	    std::cout << errorMessage<< nextLineHeader;
	  } else {
		  startTime = clock();

		  int return_code = deleteRecord(duck_db_ptr,keyIndex);

		  finishTime = clock();


	  }
  }
}

int insertRecord(bplus_tree* treePtr, int* index, value_t* values) {
  key_t key;
  intToKeyT(&key,index);
  return (*treePtr).insert(key, *values);
}

int deleteRecord(bplus_tree* zhanghuan_db_ptr, int* index) {
  key_t key;
  intToKeyT(&key,index);

  return (*treePtr).remove(key);
}




// int to key_t
void intToKeyT(bpt::key_t *a,int *b){
  char key[16] = { 0 };
  sprintf(key, "%d", *b);
  *a = key;
}

bool is_file_exist(const char* filename) {
  std::ifstream ifile(filename);   // input file stream
  return ifile.good();
}


int main(int argc, char* argc[]) {
  initialSystem();
  return 0;
}
