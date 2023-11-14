# Changelog for c++ jet peer

## v2.0.9
- No exceptions on asynchronous calls. All errors will result in execution of
  response callback with an error object

## v2.0.8
- fix memory leak on exception while sending requests having a response callback

## v2.0.6
- cmake fix for creation of version header

## v2.0.5
- jsoncpprpcException.what() returns the complete error information

## v2.0.4
- Documentation tweaks.
- Use newer libhbm version 1.0.65.

## v2.0.3
 - Check composed message before sending. This is temporarily for bug hunting

## v2.0.2
 - Binary dump of unparsable message for forensic analysis.

## v2.0.1
 - New Class PeerAsyncMock for unit testing of state and method callback methods
 - Fix handling of oversized messages

## v2.0.0
 - INTERFACE CHANGE: sync peer provides synchronous calls only. Use getAsyncPeer() to get access
   to asynchronous calls.

## v1.3.0
 - NEW: A request for changing a state might return a warning in 
   the results object of the response now. 
   Warnings will be expressed as a warning object in the result.
   Synchronous setState() Methods return an SetStateResult object containing 
   that information.

## v1.2.18
 - Fix starvation in AsyncRequest::handleResult(): Mutex should synchronize 
   access to the contaier only.

## v1.2.17
 - Require jsoncpp 1.9.5

## v1.2.16
 - Use cmake standard install paths.

## v1.2.15
 - fix jetexec
 - fix version information for pkg-config
 - fix jsoncpprpc_exception
 - fix crosscompiling issues
 - Add coverage to CI

## v1.2.14
 - fixed cmake option prefix
 - use libhbm v.1.0.62

## v1.2.13
 
 - jetpeerasync allows reciving events using an external eventloop.
   For this purpose, getReceiverEvent() provides the event to listen to.
   receive() is to be called to handle received data.
 - Fix handling of match rule "caseInsensitive"
 - More testing
  
## v1.2.12

 - Fix error handling for jet methods

## v1.2.11

 - Support matching "containsAllOf" and "caseInsensitive"
 - Make jetexec parse the parameters as Json

## v1.2.10
 - use jsoncpp v1.9.3
 - use libhbm v1.0.60

## v1.2.9
 - Catch exceptions from callback
 - Fix building static library
 - Documentation

## v1.2.8
 - Fix cmake versioning

## v1.2.7
 - Documentation
 - Fix cmake fetch_content
 - Add test coverage support

## v1.2.6
 - jsoncpp is found using cmake find_package

## v1.2.1
 - Fix md5sum of libhbm

## v1.2.0
 - Use abstract unix domain socket addresses. 
 - BREAKING CHANGE: This and all later versions requires cjet v1.5.0 or higher
   when using unix domain sockets!

## v1.1.0
 - No extension .bin for executables under linux
 - tool/jetstate gets parameters

## v1.0.30
 - Remove obsolete tool execasync

## v1.0.29
 - Require jsoncpp 1.9.2
 - Return to pkgconfig. ptxdist has problems with cmake find_package

## v1.0.28
 - Fix cmake find_package

## v1.0.27
 - Support cmake find_package
 - Use C++11 features for more efficiency

## v1.0.26
 - Introduce a maximum message size MAX_MESSAGE_SIZE. It is defined in 
   jet/defines.h
 - Add some missing methods to simulation

## v1.0.25
 - Fix logging
 
## v1.0.24
 - More tests
 - More Logging

## v1.0.23
 - Windows: Not compatible with Windows XP anymore. We use windows platforms 
   sdk 8.1 and windows platform toolset v1.41
 - New methods PeerAsync::infoAsync() and peer::info()

## v1.0.22
 - Simulation has to call the provided response callbacḱ

## v1.0.21
 - Revert change from v1.0.20: It is important to read data from jet daemon 
   as fast as possible
 - Asynchronous requests without a result callback do not send a request id 
   and won't get a response from the jet daemon.

## v1.0.20
 - Fair event handling: Give control back to event loop after each request

## v1.0.19
 - Windows: Uses tcp/ip to localhost instead of unix domain socket
 - More testing
 - More error logging

## v1.0.18
 - Linux: Constant with default unix domain socket file of cjet
 - Linux: jet peer singleton uses communication via unix domain socket

## v1.0.17
 - Linux: Support UNIX domain sockets

## v1.0.16
 - Fix error object created by jsoncpprpcException

## v1.0.15
 - when setting complex states, a resulting jsonrpc error object might contain 
   information about each sub element that coul not be set.
 - Call response callback methods in simulation

## v1.0.14
 - raise required versions of libraries
 - improve some tools

## v1.0.13
 - windows needs a terminating zero when parsing json

## v1.0.12
 - fix simulation

## v1.0.11
 - fix pkg-config

## v1.0.10
 - new method hbm::jet::Peer::getAsyncPeer() gives the asyncronuous peer 
   contained in the synchronous peer
 
## v1.0.9
 - fix build system issues for tools

## v1.08
 - Reduce build time by generating documentation on demand only
 - Do not build static libraries

## v1.0.4 - v1.0.7
 - fix build system issues

## v1.0.3
 - fix peer simulation

## v1.0.2
 - update to hbmlib 1.0.8

## v1.0.1
 - documentation 
 - use more efficient way to send sveral data small blocks

## v1.0.0
