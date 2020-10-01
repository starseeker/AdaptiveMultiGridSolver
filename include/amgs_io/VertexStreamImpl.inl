/*
Copyright (c) 2006, Michael Kazhdan and Matthew Bolitho
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list of
conditions and the following disclaimer. Redistributions in binary form must reproduce
the above copyright notice, this list of conditions and the following disclaimer
in the documentation and/or other materials provided with the distribution. 

Neither the name of the Johns Hopkins University nor the names of its contributors
may be used to endorse or promote products derived from this software without specific
prior written permission. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO THE IMPLIED WARRANTIES 
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
TO, PROCUREMENT OF SUBSTITUTE  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
DAMAGE.
*/

///////////////////////////
// MemoryInputDataStream //
///////////////////////////
template< typename Data >
MemoryInputDataStream< Data >::MemoryInputDataStream( size_t size , const Data *data ) : _data(data) , _size(size) , _current(0) {}
template< typename Data >
MemoryInputDataStream< Data >::~MemoryInputDataStream( void ){ ; }
template< typename Data >
void MemoryInputDataStream< Data >::reset( void ) { _current=0; }
template< typename Data >
bool MemoryInputDataStream< Data >::next( Data &d )
{
	if( _current>=_size ) return false;
	d = _data[_current++];
	return true;
}

////////////////////////////
// MemoryOutputDataStream //
////////////////////////////
template< typename Data >
MemoryOutputDataStream< Data >::MemoryOutputDataStream( size_t size , Data *data ) : _data(data) , _size(size) , _current(0) {}
template< typename Data >
MemoryOutputDataStream< Data >::~MemoryOutputDataStream( void ){ ; }
template< typename Data >
void MemoryOutputDataStream< Data >::next( const Data &d )
{
	_data[_current++] = d;
}

//////////////////////////
// ASCIIInputDataStream //
//////////////////////////
template< typename Factory >
ASCIIInputDataStream< Factory >::ASCIIInputDataStream( const char* fileName , const Factory &factory ) : _factory( factory )
{
	_fp = fopen( fileName , "r" );
	if( !_fp ) ERROR_OUT( "Failed to open file for reading: %s" , fileName );
}
template< typename Factory >
ASCIIInputDataStream< Factory >::~ASCIIInputDataStream( void )
{
	fclose( _fp );
	_fp = NULL;
}
template< typename Factory >
void ASCIIInputDataStream< Factory >::reset( void ) { fseek( _fp , SEEK_SET , 0 ); }
template< typename Factory >
bool ASCIIInputDataStream< Factory >::next( Data &d )
{
	d = _factory();
	return _factory.readASCII( _fp , d );
}

///////////////////////////
// ASCIIOutputDataStream //
///////////////////////////
template< typename Factory >
ASCIIOutputDataStream< Factory >::ASCIIOutputDataStream( const char* fileName , const Factory &factory ) : _factory( factory )
{
	_fp = fopen( fileName , "w" );
	if( !_fp ) ERROR_OUT( "Failed to open file for writing: %s" , fileName );
}
template< typename Factory >
ASCIIOutputDataStream< Factory >::~ASCIIOutputDataStream( void )
{
	fclose( _fp );
	_fp = NULL;
}
template< typename Factory >
void ASCIIOutputDataStream< Factory >::next( const Data &d )
{
	_factory.writeASCII( _fp , d );
}

///////////////////////////
// BinaryInputDataStream //
///////////////////////////
template< typename Factory >
BinaryInputDataStream< Factory >::BinaryInputDataStream( const char* fileName , const Factory &factory ) : _factory(factory)
{
	_fp = fopen( fileName , "rb" );
	if( !_fp ) ERROR_OUT( "Failed to open file for reading: %s" , fileName );
}
template< typename Factory >
void BinaryInputDataStream< Factory >::reset( void ) { fseek( _fp , SEEK_SET , 0 ); }
template< typename Factory >
bool BinaryInputDataStream< Factory >::next( Data &d )
{
	d = _factory();
	return _factory.readBinary( _fp , d );
}

////////////////////////////
// BinaryOutputDataStream //
////////////////////////////
template< typename Factory >
BinaryOutputDataStream< Factory >::BinaryOutputDataStream( const char* fileName , const Factory &factory ) : _factory(factory)
{
	_fp = fopen( fileName , "wb" );
	if( !_fp ) ERROR_OUT( "Failed to open file for writing: %s" , fileName );
}
template< typename Factory >
void BinaryOutputDataStream< Factory >::next( const Data &d ){ return _factory.writeBinary( _fp , d ); }

