//Programmed by: Alexander Osborn
//Email: axo095120@utdallas.edu
//CS3377.002
#include <stdint.h>

const int maxRecordStringLength = 25;

class BinaryFileHeader {
public:
  uint32_t magicNumber;
  uint32_t versionNumber;
  uint64_t numRecords;
};

class BinaryFileRecord {
  uint8_t strLength;
  char stringBuffer[maxRecordStringLength];
};

