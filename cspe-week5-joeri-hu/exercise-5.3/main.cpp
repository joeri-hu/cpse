#include <iostream>
#include <fstream>
#include <string>

#include "compressor.hpp" 
#include "decompressor.hpp" 
#include "generator.hpp"

int main( void ){	
   std::ifstream f1;
   std::string source{"wilhelmus.txt"};
   f1.open( source );
   if( ! f1.is_open()){
      std::cerr << "input file not opened";
      return -1;      
   }
   
   std::ofstream f2;
   std::string dest{"compressed.asm"};
   f2.open( dest );
   if( ! f2.is_open()){
      std::cerr << "output file not opened";
      return -1;      
   }

   lz_compressor< 4096 > compressor;
   {
      generator assembler{f2};
      compressor.compress( 
         [ &f1 ]()-> int { auto c = f1.get(); return f1.eof() ? '\0' : c; },
         [ &assembler ]( char c ){ assembler.body(c); }
      );
   }
   f1.close();
   f2.close();
   
   f1.open( dest );
   if( ! f1.is_open()){
      std::cerr << "compressed file not opened";
      return -1;
   }

   lz_decompressor decompressor;
   decompressor.decompress( 
      [ &f1 ]()-> int { auto c = f1.get(); return f1.eof() ? '\0' : c; },
      []( char c ){ std::cout << c; }
   );
}
