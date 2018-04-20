/*
 * Usage of CDK Matrix
 *
 * File:   example1.cc
 * Author: Stephen Perkins
 * Email:  stephen.perkins@utdallas.edu
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include "cdk.h"
#include "program6.h"


#define MATRIX_WIDTH 3
#define MATRIX_HEIGHT 5
#define BOX_WIDTH 25
#define MATRIX_NAME_STRING "Enter the Matrix"

using namespace std;


int main()
{

  WINDOW	*window;
  CDKSCREEN	*cdkscreen;
  CDKMATRIX     *myMatrix;           // CDK Screen Matrix

  const char 		*rowTitles[MATRIX_HEIGHT+1] = {"X", "a", "b", "c", "d", "e"};
  const char 		*columnTitles[MATRIX_WIDTH+1] = {"X", "a", "b", "c"};
  int		boxWidths[MATRIX_WIDTH+1] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int		boxTypes[MATRIX_WIDTH+1] = {vMIXED, vMIXED, vMIXED, vMIXED};

  
  //Start with some file reading
  ifstream infile;
  infile.open("cs3377.bin", ios::in | ios::binary);
  if(infile.is_open()) {
    cout << "File open success!" << endl;
  } else {
    cerr << "Runtime error: Could not open cs3377.bin" << endl;
    _exit(1);
  }
  
  BinaryFileHeader *bfh = new BinaryFileHeader();
  infile.read((char *) bfh, sizeof(BinaryFileRecord));
  
  //Output the values
  //cout << "Magic number: " << hex << showbase << bfh->magicNumber << endl;
  //cout.unsetf(ios::hex); cout.unsetf(ios::showbase);
  //cout << "Version number: " << bfh->versionNumber << endl;
  //cout << "numRecords: " << bfh->numRecords << endl;

  /*
   * Initialize the Cdk screen.
   *
   * Make sure the putty terminal is large enough
   */
  window = initscr();
  cdkscreen = initCDKScreen(window);

  /* Start CDK Colors */
  initCDKColor();

  /*
   * Create the matrix.  Need to manually cast (const char**) to (char **)
  */
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH,
			  MATRIX_NAME_STRING, (char **) rowTitles, (char **) columnTitles, boxWidths,
				     boxTypes, 1, 1, ' ', ROW, true, true, false);

  if (myMatrix ==NULL)
    {
      printf("Error creating Matrix\n");
      _exit(1);
    }

  /* Display the Matrix */
  drawCDKMatrix(myMatrix, true);

  //Set Matrix header text here

  string magicNumber;
  ostringstream dirtyConverter;
  dirtyConverter << "Magic: 0x" << hex << uppercase << bfh->magicNumber;
  magicNumber = dirtyConverter.str();
  setCDKMatrixCell(myMatrix, 1, 1, magicNumber.c_str());
  
  string magicWord;
  ostringstream cleanConverter;
  cleanConverter << "Version: " << bfh->versionNumber;
  magicWord = cleanConverter.str();
  setCDKMatrixCell(myMatrix, 1, 2, magicWord.c_str());

  ostringstream cleanerConverter;
  cleanerConverter << "NumRecords: " << bfh->numRecords;
  magicWord = cleanerConverter.str();
  setCDKMatrixCell(myMatrix, 1, 3, magicWord.c_str());

  //Read the records
  BinaryFileRecord *bfr = new BinaryFileRecord();
  //int index = 2;
  
  /*while(infile.read((char *) bfr, sizeof(BinaryFileRecord))){
    //Set left cell
    cleanerConverter.str(""); //Clear out the sstream object
    cleanerConverter << "strlen: " << bfr->strLength;
    magicWord = cleanerConverter.str();
    setCDKMatrixCell(myMatrix, index, 1, magicWord.c_str());

    //Set right (middle) cell
    setCDKMatrixCell(myMatrix, index, 2, bfr->stringBuffer);

    index++;
    if(index > 5)
      break;
      }*/

  drawCDKMatrix(myMatrix, true);    /* required  */

  /* so we can see results */
  sleep (15);


  // Cleanup screen
  endCDK();
}
