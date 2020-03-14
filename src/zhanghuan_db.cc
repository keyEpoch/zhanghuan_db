#include <iostream>



const char* nextLineHeader = "> ";

// function prototypes
void printHelpMessage();





// initial
void initialSystem() {
  // step 1: print help message
  printHelpMessage();

  // TODO
  // step 2: init database from file
  // use a b+ tree, if u do not know b+ tree
  // google that first
  

  // TODO
  // step 3: interact with command line 
  // insert, delete, update, search
  
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




int main(int argc, char* argc[]) {
  initialSystem();
  return 0;
}
