#include <string>
#include <iostream>

//캐릭터 생성을 위한 각 부품 정의
class Life {
public:
	Life(int life) :life(life) {}
	int getLife() { return life; }
private:
	int life;
};

class Power {
public:
	Power(int power) : power(power) {}
	int getPower() { return power; }
private:
	int power;
};

class Skill {
public:
	Skill(std::string skill) : skill(skill) {}
	std::string getSkill() { return skill; }
private:
	std::string skill;
};

class Name {
public:
	Name(std::string name) : name(name) {}
	std::string getName() { return name; }
private:
	std::string name;
};

//캐릭터 정의
class Character {
public:
	Character() {}
	~Character() {
		if (life) delete life;
		if (power) delete power;
		if (skill) delete skill;
		if (name) delete name;
	}
	void printInfo() {
		std::cout << "Life: " << life->getLife() << std::endl;
		std::cout << "Power: " << power->getPower() << std::endl;
		std::cout << "Skill: " << skill->getSkill() << std::endl;
		std::cout << "Name: " << name->getName() << std::endl;
	}
	void setLife(Life* life) { this->life = life; }
	void setPower(Power* power) { this->power = power; }
	void setSkill(Skill* skill) { this->skill = skill; }
	void setName(Name* name) { this->name = name; }
private:
	Life* life;
	Power* power;
	Skill* skill;
	Name* name;
};

// 캐릭터 조립을 위한 빌더
class Builder {
public:
	virtual Life* buildLife() = 0;
	virtual Power* buildPower() = 0;
	virtual Skill* buildSkill() = 0;
	virtual Name* buildName() = 0;
};

// 특정 캐릭터 조립: 피콜로
class PicoloBuilder : public Builder {
	Life* buildLife() override { return new Life(70); }
	Power* buildPower() override { return new Power(100); }
	Skill* buildSkill() override { return new Skill("Fragment"); }
	Name* buildName() override { return new Name("Picolo"); }
public:
	~PicoloBuilder() { std::cout << "Destruct Picolo\n"; }
};

// 특정 캐릭터 조립: 손오반
class SonobanBuilder : public Builder {
	Life* buildLife() override { return new Life(100); };
	Power* buildPower() override { return new Power(150); };
	Skill* buildSkill() override { return new Skill("EnergyBeam"); };
	Name* buildName() override { return new Name("Sonoban"); };
public:
	~SonobanBuilder() { std::cout << "Destruct Sonoban\n"; }
};

class Director
{
public:
	Director() :builder_(nullptr) {}
	Director(Builder* builder) :builder_(builder) {}
	//~Director() { if (builder_) delete builder_; }
	//어떤 Builder를 사용할 것인가?
	void setDirector(Builder* builder) {
		builder_ = builder;
	}
	//캐릭터 만들기
	Character* constructor() {
		Character* character = new Character;
		character->setLife(builder_->buildLife());
		character->setName(builder_->buildName());
		character->setPower(builder_->buildPower());
		character->setSkill(builder_->buildSkill());
		return character;
	}
private:
	Builder* builder_;
};

int main() {
	//Case 1:
	/*PicoloBuilder* pb = new PicoloBuilder;
	SonobanBuilder* sb = new SonobanBuilder;
	Director director;
	director.setDirector(pb);
	Character* picolo = director.constructor();
	picolo->printInfo();
	director.setDirector(sb);
	Character* sonoban = director.constructor();
	sonoban->printInfo();
	delete pb;
	delete sb;*/

	/* 
	 * 런타임 에러 나는 이유
	 * 만들어진 캐릭터의 정보를 모두 출력하고 동적할당한 빌더들을 모두해제
	 * 메인함수가 끝나고 0을 리턴하기전에 director의 소멸자가 호출됨
	 * director는 맴버 변수로 빌더를 가리키는 포인터를 가지고 있는데 위에서 delete를 한 빌더를 또 delete함
	 * 따라서 런타임 에러가 발생함, 해결하기 위해서 shared_ptr과 weak_ptr을 사용하는 것이 좋아 보임.
	 */

	//Case 2:
	// Buggy code. Why???
	Director director;
	PicoloBuilder picoloBuilder;
	SonobanBuilder sonobanBuilder;
	director.setDirector(&picoloBuilder);
	Character *picolo = director.constructor();
	picolo->printInfo();
	director.setDirector(&sonobanBuilder);
	Character *sonoban = director.constructor();
	sonoban->printInfo();
	delete picolo;
	delete sonoban;

	/*
	 * 런타임 에러 나는 이유
	 * 빌더들을 동적으로 생성하지 않았기 때문에 메인함수가 끝나면서 director의 소멸자가 호출될때
	 * 해제된 메모리를 delete하려고 해서 오류가 발생함
	 */

	return 0;
}