//6356
#include <iostream>
#include <string>

class Weapon {
	protected :
	std::string weaponName;

public :
	
	explicit Weapon(){
		weaponName = "no Weapon Name";
	}

	Weapon(std::string wN)
	: weaponName(wN){}
	
	
	std::string getWeaponName()  {
    	return weaponName;
	}
	
	void setWeaponName(std::string WeaponName) {
    	weaponName = WeaponName;
	}
	
	~Weapon() {}
	
	
};

class ExoticWeapon : public Weapon{
	std::string origin;

public:
ExoticWeapon(): Weapon(){}
	
	std::string getOrigin()  {
    	return origin;
	}
	
	void setOrigin(std::string Origin) {
    	origin = Origin;
	}
	
	~ExoticWeapon() {}

}; 

class Samurai {
protected:
	std::string name;
    int numberOfWins;
    int numberOfInjuries;
    int numberOfDuels;
    
    std::string samuraiWeapon;
	int age;
	
public :

	explicit Samurai(){
		samuraiWeapon = "no Weapon";
	}
	
    Samurai(std::string W, const int X, const int Y, const int Z, std::string U,  const int V )
    : name(W), numberOfWins(X), numberOfInjuries(Y), numberOfDuels(Z), samuraiWeapon(U), age(V)
    {U="no weapon";
	}

    std::string getName()  {
    	return name;
	}
    int getNumberOfWins()  {
    	return numberOfWins;
	}

	int getNumberOfDuels()  {
   		return numberOfDuels;
	}

	int getNumberOfInjuries() {
    	return numberOfInjuries;
	}

	std::string getSamuraiWeapon()  {
    	return samuraiWeapon;
	}

	int getAge()  {
    	return age;
	}
	
    void setName(std::string Name) {
    	name = Name;
	}

	void setNumberOfWins(int wins) {
    	numberOfWins = wins;
	}

	void setNumberOfInjuries(int injuries) {
    	numberOfInjuries = injuries;
	}

	void setNumberOfDuels(int duels) {
    	numberOfDuels = duels;
	}
   
   void setSamuraiWeapon(std::string SamuraiWeapon) {
    	samuraiWeapon = SamuraiWeapon;
	}
	
	void setAge(int Age) {
    	age = Age;
	}
	
	void printSamuraiDescription()  {
    	std::cout << "Samurai name: " << name
             	 << " Duels: "       << numberOfDuels
            	  << " Wins: "        << numberOfWins
             	 << " Injuries: "    << numberOfInjuries
             	 << " Weapon: " << samuraiWeapon
             	 << " Age: " << age
             	 << "\n";
	}
    
    ~Samurai() {
   		std::string temp = name;
   		numberOfDuels = 0;
    	numberOfInjuries = 0;
   		numberOfWins = 0;
   		samuraiWeapon = "no weapon";
   		age = 0;
	}
	
	void pickWeapon(  Weapon &a){
		if (age<18 ) 	{
			setSamuraiWeapon("Wooden Sword");		}	
		else {
			setSamuraiWeapon (a.getWeaponName());	} 
	}

};

class Ninja : public Samurai{
	int grade;
	
public:
	Ninja() : Samurai(){}
		
	int getGrade()  {
    	return grade;
	}
	
	void setGrade(int Grade) {
    	grade = Grade;
	}
	
	void pickExoticWeapon(ExoticWeapon &a){
		setSamuraiWeapon (a.getWeaponName());
	}
	
	~Ninja() {}
	
};

class NinjaSchool{
	Ninja* ninjaClass;
	int numberOfStudents;
	
public:
	
	NinjaSchool(){
	ninjaClass = new Ninja[10];
	numberOfStudents=0;
	}	

 	 NinjaSchool operator++(){
 		if (numberOfStudents<10){
		 numberOfStudents++;
  		return *this;
 		}
	}
	NinjaSchool operator++(int){
		if (numberOfStudents<10){
		NinjaSchool temp=*this;
 		numberOfStudents++;
 		return temp;
 		}
	}
	  NinjaSchool operator--(){
	 	if (numberOfStudents>0){
 		numberOfStudents--;
 		return *this;
 		}
	}
	 NinjaSchool operator--(int){
		if (numberOfStudents>0){
		NinjaSchool temp=*this;
 		numberOfStudents--;
 		return temp;
 		}
	 }
	 
 Ninja startTrainingNinja(Samurai &a){
		Ninja b;
		b.setGrade(0);
		b.setAge(a.getAge());
		b.setName(a.getName());
		b.setNumberOfDuels(a.getNumberOfDuels());
		b.setNumberOfInjuries(a.getNumberOfInjuries());
		b.setNumberOfWins(a.getNumberOfWins());
		b.setSamuraiWeapon(a.getSamuraiWeapon());
		return b;
		
	}
	
	
	void addNinjaToNinjaClass(Ninja &a){
		if(a.getAge()<18){
			std::cout<<"This class is for grownups!";
		}
		else{
			ninjaClass[numberOfStudents]=a;
			numberOfStudents++;
		}
	}
	
	std::string brawlWithNinjas(){
		int max= ninjaClass[0].getGrade();
		std::string maxname = ninjaClass[0].getName();
		int i;
		
		for (i=1;i<=numberOfStudents;i++){
			if(ninjaClass[i].getGrade()>max){
				max = ninjaClass[i].getGrade();
				maxname = ninjaClass[i].getName();
			}
		}
		return maxname;
	}
};



void duelForYoungSamurais(Samurai &a,Samurai &b) {
	
	if((a.getAge()>18) || (b.getAge()>18)){
		std::cout<<"Invalid duel!"; 
		}
	else if (a.getSamuraiWeapon() == "Wooden Sword" && b.getSamuraiWeapon() == "Wooden Sword"){
		std::cout<<"Duel postponed!";
		}
	else {
		std::cout<< a.getName() <<" duels "<<b.getName()<<"!";
	}
}

void duel(Samurai &a, Samurai &b, bool winner) {
   
    if (winner) {
        a.setNumberOfWins(a.getNumberOfWins() + 1);
        b.setNumberOfInjuries(b.getNumberOfInjuries() + 1);
        if (a.getNumberOfWins() > 10) {
            std::cout << "Samurai " << a.getName() << " is duelist.";
        }
    }
    else {
        b.setNumberOfWins(b.getNumberOfWins() + 1);
        a.setNumberOfInjuries(a.getNumberOfInjuries() + 1);
        if (b.getNumberOfWins() > 10) {
            std::cout << "Samurai " << b.getName() << " is duelist.";
        }
    }

    a.setNumberOfDuels(a.getNumberOfDuels() + 1);
    b.setNumberOfDuels(b.getNumberOfDuels() + 1);
}

std::string duelWithWeapons(Samurai &a, Samurai &b){
	
	if((a.getAge()<18) || (b.getAge()<18)){
		return "This duel is for adults only!"; 
	}
	else if ((a.getSamuraiWeapon() !="Rock" && a.getSamuraiWeapon() !="Scissors" && a.getSamuraiWeapon() !="Paper") || (b.getSamuraiWeapon() !="Rock" && b.getSamuraiWeapon() !="Scissors" && b.getSamuraiWeapon() !="Paper")){
		return "Strange Duel!";
	}	
	else {
		
		if (a.getSamuraiWeapon() == b.getSamuraiWeapon()){
			return "The duel is draw!";
		}
		else if (a.getSamuraiWeapon() == "Rock" && b.getSamuraiWeapon() == "Scissor"){
			return a.getName();
		}
		else if (b.getSamuraiWeapon() == "Rock" && a.getSamuraiWeapon() == "Scissor"){
			return b.getName();
		}
		else if (a.getSamuraiWeapon() == "Scissor" && b.getSamuraiWeapon() == "Paper"){
			return a.getName();
		}
		else if (b.getSamuraiWeapon() == "Scissor" && a.getSamuraiWeapon() == "Paper"){
			return b.getName();
		}
		else if (a.getSamuraiWeapon() == "Paper" && b.getSamuraiWeapon() == "Rock"){
			return a.getName();
		}
		else if (b.getSamuraiWeapon() == "Paper" && a.getSamuraiWeapon() == "Rock"){
			return b.getName();
		}
		
	}
		

}



