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
//#include "cdk.h"
#include "program6.h"


#define MATRIX_WIDTH 3
#define MATRIX_HEIGHT 5
#define BOX_WIDTH 25
#define MATRIX_NAME_STRING "Enter the Matrix"

using namespace std;


int main()
{
  
  //Start with some file reading
  ifstream infile;
  infile.open("cs3377.bin", ios::in | ios::binary);
  if(infile.is_open()) {
    cout << "File open success!" << endl;
  } else {
    cerr << "Runtime error: Could not open cs3377.bin" << endl;
    
  }
  
  BinaryFileHeader *bfh = new BinaryFileHeader();
  //for (int i = 0; i < 3; i++)
  infile.read((char *) bfh, sizeof(BinaryFileHeader));
  //int magicNumber = bfh->magicNumber;
  cout << "Magic: " << bfh->magicNumber << endl;
  cout << "Version: " << bfh->versionNumber << endl;
  cout << "NumRecords: " << bfh->numRecords << endl;
  
  BinaryFileRecord *bfr = new BinaryFileRecord();
  while(infile.read((char *) bfr, sizeof(BinaryFileRecord))){

    string magicWord = bfr->stringBuffer;
    cout << "strlen: " << magicWord.length() << endl;
    cout << "Record: " << magicWord << endl;
  }

  //infile.read((char *) bfh, sizeof(BinaryFileHeader));
  //int magicNumber = bfh->magicNumber;
  //cout << "Magic: " << magicNumber << endl;

  /*  string magicNumber;
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
  */
}
