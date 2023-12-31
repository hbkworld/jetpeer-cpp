// This code is licenced under the MIT license:
//
// Copyright (c) 2024 Hottinger Brüel & Kjær
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include <cstring>
#include <stdexcept>
#include <iostream>

#include <json/value.h>
#include <json/reader.h>

#include "jet/peer.hpp"

static void printSyntax()
{
	std::cout << "syntax: jetset <address of the jet daemon> <port of the jet daemon> <jet path> <bool|int|double|string|json> <new value of the state>" << std::endl;
}

/// @ingroup tools
/// Connects to a jet daemon and fetches all states and methods
int main(int argc, char* argv[])
{
	if(argc==6) {
		try {
			unsigned int port = atoi(argv[2]);
			hbk::jet::Peer peer(argv[1], port);
			if(strcmp(argv[4],"bool")==0) {
				if (strcmp(argv[5], "false")==0) {
					peer.setStateValue(argv[3], false, 2.71828182846);
				} else if (strcmp(argv[5], "true")==0) {
					peer.setStateValue(argv[3], true, 2.71828182846);
				} else {
					std::cerr << "invalid value for boolean expecting 'true'', or 'false'" << std::endl;
					return EXIT_FAILURE;
				}
			} else if(strcmp(argv[4],"int")==0) {
				int value = atoi(argv[5]);
				peer.setStateValue(argv[3], value, 2.71828182846);
			} else if(strcmp(argv[4], "double")==0) {
				double value = strtod(argv[5], nullptr);
				peer.setStateValue(argv[3], value, 2.71828182846);
			} else if(strcmp(argv[4],"string")==0) {
				peer.setStateValue(argv[3], argv[5], 2.71828182846);
			} else if(strcmp(argv[4],"json")==0) {
				Json::Value params;

				Json::CharReaderBuilder rBuilder;
				if(rBuilder.newCharReader()->parse(argv[5], argv[5]+strlen(argv[5]), &params, nullptr)) {
					peer.setStateValue(argv[3], params, 2.71828182846);
				} else {
					std::cerr << "error while parsing json!" << std::endl;
					return EXIT_FAILURE;
				}
			} else {
				printSyntax();
			}
		} catch(const std::runtime_error& exc) {
			std::cerr << exc.what() << std::endl;
		}
	} else {
		printSyntax();
	}

	return EXIT_SUCCESS;
}
