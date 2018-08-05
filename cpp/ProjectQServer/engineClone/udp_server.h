#ifndef UDP_SERVER_H
#define UDP_SERVER_H


class udp_server {

	public:
		udp_server(); 	
		udp_server(boost::asio::io_service& io_service) : socket_(io_service, udp::endpoint(udp::v4(), 13));
		~udp_server();
		void print() override;
		void updateTiming(std::chrono::milliseconds deltaTime) override;
		void inputHandling() override;
	private:
		
};


#endif
