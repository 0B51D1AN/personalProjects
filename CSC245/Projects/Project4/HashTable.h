        #ifndef _SEPARATE_CHAINING_H_
        #define _SEPARATE_CHAINING_H_

        #include <vector>
        #include <string> 
        #include "LinkedList.h"

        // SeparateChaining Hash table class
        //
        // CONSTRUCTION: an initialization for ITEM_NOT_FOUND
        //               and an approximate initial size or default of 101
        //
        // ******************PUBLIC OPERATIONS*********************
        // void insert( x )       --> Insert x
        // void remove( x )       --> Remove x
        // Hashable find( x )     --> Return item that matches x
        // void makeEmpty( )      --> Remove all items
        // int hash( string str, int tableSize )
        //                        --> Global method to hash strings

        template <class HashedObj>
        class HashTable
        {
          public:
            explicit HashTable( const HashedObj & notFound, int size = 101 );
            //Sample Use:  HashTable<string> h("ZZZ", 50);

            HashTable( const HashTable & rhs )
              : ITEM_NOT_FOUND( rhs.ITEM_NOT_FOUND ), theLists( rhs.theLists ) { }

            const HashedObj & find( const HashedObj & x ) const;

            void makeEmpty( );
            void insert( const HashedObj & x );
            void remove( const HashedObj & x );

            const HashTable & operator=( const HashTable & rhs );
            int hash( const string& key, int tableSize ) const;
            int hash( int key, int tableSize ) const;

          private:
            vector<List<HashedObj> > theLists;   // The array of Lists
            const HashedObj ITEM_NOT_FOUND;
        };
        #include "HashTable.cpp"
        #endif
