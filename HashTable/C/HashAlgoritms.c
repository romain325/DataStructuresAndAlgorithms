// YOU CAN FIND HERE SOME ALGORITHMS USED FOR HASHING

// QUICK HELP
/*
The `<<` operator is used for a bit shift, if you give 5 (00000101) and do 5 << 1, you shift one bit so it became: 00001010 (10)
++ The >> operator do the exact thing but in the opposite direction ++
*/

// DJB2
unsigned long hashCode_djb2(unsigned char *str){
    unsigned long hashCode = 5381; // do not change this
    int chr;

    while(chr = *str++){
        hashCode = ((hashCode << 5) + hashCode) + chr; // hashCode *33 + chr
    }
    return hashCode;
}

// sdbm
unsigned long hashCode_sdbm(unsigned char *str){
    unsigned long hashCode = 0;
    int chr;

    while(chr = *str++){
        hashCode = chr + (hashCode << 6) + (hashCode << 16) - hashCode;
    }
    return hashCode;
}

// xor8
unsigned long hashCode_xor8(unsigned  char *str){
    unsigned long hashCode = 0;
    int chr;

    while (chr = *str++){
        hashCode = (hashCode + chr) & 0xff;
    }
    return (((hashCode ^ 0xff) + 1) & 0xff);
}

// crc32
unsigned long hashCode_crc32(unsigned char *str){
    unsigned long hashCode = 0xffffffff;
    int chr;

    while(chr = *str++){
        hashCode = hashCode ^ chr;
        for(unsigned char j = 8; j > 0; --j){
            hashCode = (hashCode >> 1) ^ (0xEDB88320 & (-(hashCode & 1)));
        }
    }
    return hashCode ^ 0xffffffff;
}

// adler_32
unsigned long hashCode_adler32(unsigned char *str){
    unsigned long hash1 = 1;
    unsigned long hash2 = 0;
    const unsigned long MODADLER = 65521;
    int chr;

    while(chr = *str++){
        hash1 = (hash1 + chr) % MODADLER;
        hash2 = (hash2 + hash1) % MODADLER;
    }
    return (hash2 << 16) | hash1;
}

// TODO Add more --> (SHA.. , MD..., RIPEMD)