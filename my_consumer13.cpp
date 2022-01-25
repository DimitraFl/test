/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (c) 2013-2015 Regents of the University of California.
 *
 * This file is part of ndn-cxx library (NDN C++ library with eXperimental eXtensions).
 *
 * ndn-cxx library is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later version.
 *
 * ndn-cxx library is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
 *
 * You should have received copies of the GNU General Public License and GNU Lesser
 * General Public License along with ndn-cxx, e.g., in COPYING.md file.  If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * See AUTHORS.md for complete list of ndn-cxx authors and contributors.
 *
 * @author Alexander Afanasyev <http://lasr.cs.ucla.edu/afanasyev/index.html>
 */

// correct way to include ndn-cxx headers
// #include <ndn-cxx/face.hpp>
#include "face.hpp"
				#include <time.h>
				#include <util/time.hpp>
				#include <util/random.hpp>
				ndn::time::system_clock::time_point sentTime;
				int total_interests=0;
				int satisfied_interests=0;
				uint64_t  total_RTT=0;
				int i;
				

char uri[180][20] = { 	          
				   "/example/temp0",
				   "/example/hum0",
				   "/example/sound0",
				   "/example/light0",
				   "/example/movement0",
				   "/example/hall0",
		 	       "/example/temp1",
				   "/example/hum1",
				   "/example/sound1",
				   "/example/light1",
				   "/example/movement1",
				   "/example/hall1",
		 	       "/example/temp2",
				   "/example/hum2",
				   "/example/sound2",
				   "/example/light2",
				   "/example/movement2",
				   "/example/hall2",
		 	       "/example/temp3",
				   "/example/hum3",
				   "/example/sound3",
				   "/example/light3",
				   "/example/movement3",
				   "/example/hall3",
		 	       "/example/temp4",
				   "/example/hum4",
				   "/example/sound4",
				   "/example/light4",
				   "/example/movement4",
				   "/example/hall4",
		 	       "/example/temp5",
				   "/example/hum5",
				   "/example/sound5",
				   "/example/light5",
				   "/example/movement5",
				   "/example/hall5",
				   "/example/temp6",
                   "/example/hum6",
                   "/example/sound6",
                   "/example/light6",
                   "/example/movement6",
                   "/example/hall6",
				   "/example/temp7",
                   "/example/hum7",
                   "/example/sound7",
                   "/example/light7",
                   "/example/movement7",
                   "/example/hall7",
				   "/example/temp8",
                   "/example/hum8",
                   "/example/sound8",
                   "/example/light8",
                   "/example/movement8",
                   "/example/hall8",
				   "/example/temp9",
                   "/example/hum9",
				   "/example/sound9",
				   "/example/light9",
				   "/example/movement9",
				   "/example/hall9", 
				   "/example/temp10",
				   "/example/hum10",
				   "/example/sound10",
				   "/example/light10",
				   "/example/movement10",
				   "/example/hall10",
		 	       "/example/temp11",
				   "/example/hum11",
				   "/example/sound11",
				   "/example/light11",
				   "/example/movement11",
				   "/example/hall11",
		 	       "/example/temp12",
				   "/example/hum12",
				   "/example/sound12",
				   "/example/light12",
				   "/example/movement12",
				   "/example/hall12",
		 	       "/example/temp13",
				   "/example/hum13",
				   "/example/sound13",
				   "/example/light13",
				   "/example/movement13",
				   "/example/hall13",
		 	       "/example/temp14",
				   "/example/hum14",
				   "/example/sound14",
				   "/example/light14",
				   "/example/movement14",
				   "/example/hall14",
		 	       "/example/temp15",
				   "/example/hum15",
				   "/example/sound15",
				   "/example/light15",
				   "/example/movement15",
				   "/example/hall15",
				   "/example/temp16",
                   "/example/hum16",
                   "/example/sound16",
                   "/example/light16",
                   "/example/movement16",
                   "/example/hall16",
				   "/example/temp17",
                   "/example/hum17",
                   "/example/sound17",
                   "/example/light17",
                   "/example/movement17",
                   "/example/hall17",
				   "/example/temp18",
                   "/example/hum18",
                   "/example/sound18",
                   "/example/light18",
                   "/example/movement18",
                   "/example/hall18",
				   "/example/temp19",
                   "/example/hum19",
				   "/example/sound19",
				   "/example/light19",
				   "/example/movement19",
				   "/example/hall19",
				   "/example/temp20",
				   "/example/hum20",
				   "/example/sound20",
				   "/example/light20",
				   "/example/movement20",
				   "/example/hall20",
		 	       "/example/temp21",
				   "/example/hum21",
				   "/example/sound21",
				   "/example/light21",
				   "/example/movement21",
				   "/example/hall21",
		 	       "/example/temp22",
				   "/example/hum22",
				   "/example/sound22",
				   "/example/light22",
				   "/example/movement22",
				   "/example/hall22",
		 	       "/example/temp23",
				   "/example/hum23",
				   "/example/sound23",
				   "/example/light23",
				   "/example/movement23",
				   "/example/hall23",
		 	       "/example/temp24",
				   "/example/hum24",
				   "/example/sound24",
				   "/example/light24",
				   "/example/movement24",
				   "/example/hall24",
		 	       "/example/temp25",
				   "/example/hum25",
				   "/example/sound25",
				   "/example/light25",
				   "/example/movement25",
				   "/example/hall25",
				   "/example/temp26",
                   "/example/hum26",
                   "/example/sound26",
                   "/example/light26",
                   "/example/movement26",
                   "/example/hall26",
				   "/example/temp27",
                   "/example/hum27",
                   "/example/sound27",
                   "/example/light27",
                   "/example/movement27",
                   "/example/hall27",
				   "/example/temp28",
                   "/example/hum28",
                   "/example/sound28",
                   "/example/light28",
                   "/example/movement28",
                   "/example/hall28",
				   "/example/temp29",
                   "/example/hum29",
				   "/example/sound29",
				   "/example/light29",
				   "/example/movement29",
				   "/example/hall29" //180 names (0-179) 
                    };  

 int x=-1;

// Enclosing code in ndn simplifies coding (can also use `using namespace ndn`)
namespace ndn {
// Additional nested namespace could be used to prevent/limit name contentions
namespace examples {

class Consumer : noncopyable
		{
		public:

		  void
		  run()
		  {
			
			int n=180; //change the number od available content names
			//bool TrueFalse = (rand() % 100) < 75;
			//The rand() % 100 will give you a random number between 0 and 100, and the probability of it being under 75 is, well, 75%. 
			//You can substitute the 75 for any probability you want.

		        //Calculate starting time
			sentTime=time::system_clock::now();
			//std::cout << "\t sentTime: " << sentTime << std::endl;

			//srand((time::system_clock::now() -  sentTime).count());
			//std::cout << "n= " << n << std::endl;
			
                       Interest interest;
                       x=x+1;
                       i=(rand() % n);
                       std::cout << "Random number is: " << i << std::endl;
                       interest.setName(uri[i]);
		        interest.setInterestLifetime(time::milliseconds(3600000)); //change the lifetime
		        interest.setMustBeFresh(true);

		         m_face.expressInterest(interest,
					          bind(&Consumer::onData, this,  _1, _2),
					          bind(&Consumer::my_onTimeout, this, _1));                 
                    
		         std::cout << "Sending " << interest << std::endl;

		         total_interests++;
		         std::cout << "\t Total interests :" << total_interests <<"\n\n"<< std::endl;
		         // std::cout << "\t Time:"<< time::toString(time::system_clock::now()) << std::endl;

		     

		     // processEvents will block until the requested data received or timeout occurs
		     m_face.processEvents();
		  }

		void
		  my_onTimeout(const Interest& interest)
		  {
		        Interest retrasmit;
		        std::cout << "Timeout " << interest << std::endl;
		        //retrasmission
	                retrasmit.setName(uri[i]);
		        retrasmit.setInterestLifetime(time::milliseconds(3600000)); //change the lifetime
		        retrasmit.setMustBeFresh(true); 
		        m_face.expressInterest(retrasmit,bind(&Consumer::onData, this,  _1, _2),
					             bind(&Consumer::my_onTimeout, this, _1));
			std::cout << "Retrasmit " << retrasmit << std::endl;	            
			total_interests++;
		       std::cout << "\t Total interests :" << total_interests <<"\n\n"<<std::endl;		
		  }


		private:
		  void
		  onData(const Interest& interest, const Data& data)
		  {
				std::cout << data << std::endl;
				double roundTripTime;
				satisfied_interests++;
				std::cout << "From interest: " << interest << std::endl;
				//	std::cout << "\t Time:"<< time::toString(time::system_clock::now()) << std::endl;
				roundTripTime = (time::system_clock::now() -  sentTime).count() / 1000000.0;
				std::cout <<"\t RTT:" <<roundTripTime << "\n\n\n\n"<< std::endl;
				total_RTT=total_RTT + roundTripTime;
		  }

		private:
		  Face m_face;
		};

} // namespace examples
} // namespace ndn


int
main(int argc, char** argv)
{
	 ndn::examples::Consumer consumer;
	 const int rep= 20; //change the number of repetitions

	srand((ndn::time::system_clock::now() -  sentTime).count());
	
	 for (int y=0; y<rep; y++)
	 {
		  try {
			consumer.run();
		  }
		  catch (const std::exception& e) {
			std::cerr << "ERROR: " << e.what() << std::endl;
		  }
	}

	std::cout <<"\t Total RTT:" <<total_RTT/satisfied_interests << std::endl;
	std::cout <<"\t Success Ratio:" <<(double)satisfied_interests/total_interests << std::endl; //ISR
	std::cout <<"\t Satisfied interests:" <<satisfied_interests << std::endl;
	return 0;
}
