// File credit: http://www.vilipetek.com/2013/11/22/zippingunzipping-files-in-c/

// Modified by Henryk Blasinski

#pragma once
#include <ioapi.h>
#include <unzip.h>
#include <string>
#include <vector>
#include <iostream>

namespace ziputils
{
	class unzipper
	{
	public:
		unzipper();
		~unzipper(void);

		bool open( const char* filename );
		void close();
		bool isOpen();

        void extractToDirectory(const char* directoryName);
        
		bool openEntry( const char* filename );
		void closeEntry();
		bool isOpenEntry();
		unsigned int getEntrySize();

		const std::vector<std::string>& getFilenames();
		const std::vector<std::string>& getFolders();

		unzipper& operator>>( std::ostream& os );

	private:
		void readEntries();

	private:
		unzFile			zipFile_;
		bool			entryOpen_;

		std::vector<std::string> files_;
		std::vector<std::string> folders_;
	};
};
