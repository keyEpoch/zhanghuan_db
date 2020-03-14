// Author: Huan Zhang

#include <stdlib.h>
#include <stdio.h>

namespace bpt {

/* meta info of B+ tree */
typedef struct {
  size_t order;              // order of B+ tree  
  size_t value_size;         // size of value
  size_t key_size;           // size of key
  size_t internal_nodes_num; // number of internal_nodes
  size_t leaf_nodes_num;     // number of leaf nodes 
  size_t height;             // height of tree (exclude leaves)

  off_t slot;                // where to store new block
  off_t root_offset;         // where is the root of internal nodes
  off_t leaf_offset;         // where is the first leaf
} meta_t;


class bplus_tree {
public:
  // construstor
  bplus_tree(const* char filepath, bool force_empty = false);

  // functions
  int search();
  int search_range();
  int remove();
  int insert();
  int update();

  meta_t get_meta() const {
	  return meta;
  }

private:
  meta_t meta;      // meta info of B+ tree
  char path[512];   // file path


  // multi-level file open & close
  mutable FILE* fp;
  mutable int fp_level;
  void open_file(const char* mode = "rb+") const {
	// "rb+" will make sure we can write everywhere without truncating file
	if (fp_level == 0)  // never opened 
      fp = fopen(path, mode);
	++fp_level;
	// variables in const scope can not be changed
	// mutable can specify minority variables changeable in const scope
	// so mutable can enhance flexibility
  }

  void close_file() const {
    if (fp_level == 1)  // have been opened
      fclose(fp);
    --fp_level;
  }



};

}


