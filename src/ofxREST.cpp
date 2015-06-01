#include "ofxREST.h"

#ifdef _MSC_VER
#ifdef _DEBUG
#pragma comment(lib, "cpprest110d_2_5.lib")
#else
#pragma comment(lib, "cpprest110_2_5.lib")
#endif
#endif

#include <Windows.h>
#include <cpprest/oauth2.h>
#include <cpprest/http_listener.h>
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>

using namespace utility;
using namespace web::http;
using namespace web::http::client;
using namespace web::http::oauth2::experimental;

using namespace web::http::experimental::listener;
using namespace concurrency::streams;

void test_OAuth2()
{
//	utility::string_t redirect_uri(U("http://localhost:50001"));
	utility::string_t redirect_uri(U("http://miku-miku-metaverse.com/"));

	oauth2_config m_oauth2_config(U("00000000401566AD"), /* Your live App key*/
				U("iQpIiFEhTVKOSPOaaXbKjKbfHKZb4jfh"), /* Your live App secret*/
				U("https://login.live.com/oauth20_authorize.srf"), /* Authorization endpoint*/
				U("https://login.live.com/oauth20_token.srf"), /* Token endpoint */
				redirect_uri); /* Redirect URI */

	m_oauth2_config.set_scope(U("wl.skydrive"));
	auto auth_uri = m_oauth2_config.build_authorization_uri(true);  /* Get the authorization uri */

	try{
//		http_listener m_listener(redirect_uri);
		http_listener m_listener(L"http://localhost:50001");
		m_listener.support([&](http_request request) -> void
		{
			 m_oauth2_config.token_from_redirected_uri(request.request_uri()).then([&]() -> void
			 {
				  auto token = m_oauth2_config.token().access_token(); // Get the access token
				  printf("got token [%s]\n", token.c_str());
			 });
			 request.reply(status_codes::OK, U("Ok."));
		});
		m_listener.open().wait();
	}catch(http_exception e){
		printf("%s\n", e.what());
	}catch(std::exception e){
		printf("%s\n", e.what());
	}catch(...){
		printf("unknown error\n");
	}

	printf("Opening browser in URI: %s", auth_uri.c_str());
	// is redirect but there are no host. edit /etc/hosts please;

	while(true){
		Sleep(100);
	}

	printf("test");
	try{
		m_oauth2_config.token_from_redirected_uri(L"http://www.miku-miku-metaverse.com/?code=Mfca0e8cc-7f3c-ee92-22c0-88ac3c46fcee&state=Kv1aedg93XZcXe8kXj0YYl0kMQw6OYSe").then([&]() -> void
		{
			auto token = m_oauth2_config.token().access_token(); // Get the access token
			printf("got token [%s]\n", token.c_str());
		}).wait();
	}catch(oauth2_exception e){
		printf("%s\n", e.what());
	}catch(http_exception e){
		printf("%s\n", e.what());
	}catch(std::exception e){
		printf("%s\n", e.what());
	}catch(...){
		printf("unknown error\n");
	}

	http_client_config http_config;
	http_config.set_oauth2(m_oauth2_config);

	http_client client (U("https://apis.live.net/v5.0/"), http_config);
	printf("result %s\n", client.request(methods::GET, U("me/skydrive/my_photos")).get().extract_string().get().c_str());
	return;
}


void test_rest()
{
	test_OAuth2();
	return;

    // Open a stream to the file to write the HTTP response body into.
    auto fileBuffer = std::make_shared<streambuf<uint8_t>>();
    file_buffer<uint8_t>::open(L"test.txt", std::ios::out).then([=](streambuf<uint8_t> outFile) -> pplx::task<http_response>
    {
        *fileBuffer = outFile; 

        // Create an HTTP request.
        // Encode the URI query since it could contain special characters like spaces.
        http_client client(U("http://www.bing.com/"));
        return client.request(methods::GET, uri_builder(U("/search")).append_query(U("q"), L"test").to_string());
    })

    // Write the response body into the file buffer.
    .then([=](http_response response) -> pplx::task<size_t>
    {
        printf("Response status code %u returned.\n", response.status_code());

        return response.body().read_to_end(*fileBuffer);
    })

    // Close the file buffer.
    .then([=](size_t)
    {
        return fileBuffer->close();
    })

    // Wait for the entire response body to be written into the file.
    .wait();


    return;
}