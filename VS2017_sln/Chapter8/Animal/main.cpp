#include <iostream>
#include <windows.h>  // 用于Beep函数
#include <thread>     // 用于延时
#include <chrono>     // 用于时间控制
#include <string>

class Animal {
protected:
		std::string name;

public:
		Animal(const std::string& n) : name(n) {}

		virtual void speak() const=0;

		virtual ~Animal() {}
		std::string getName() const { return name; }
};

class Frog : public Animal {
public:
		Frog(const std::string& n) : Animal(n) {}

		void speak() const override {
				std::cout << name << "：呱呱呱！" << std::endl;
				// 青蛙：短促的连音
				Beep(800, 150);
				Beep(600, 150);
				Beep(800, 150);
		}
};

class Duck : public Animal {
public:
		Duck(const std::string& n) : Animal(n) {}

		void speak() const override {
				std::cout << name << "：嘎嘎嘎！" << std::endl;
				// 鸭子：低沉的连续声音
				Beep(400, 200);
				Beep(450, 200);
				Beep(400, 300);
		}
};

class Cat : public Animal {
public:
		Cat(const std::string& n) : Animal(n) {}

		void speak() const override {
				std::cout << name << "：喵喵喵！" << std::endl;
				// 猫：柔和的较高音
				Beep(1000, 250);
				std::this_thread::sleep_for(std::chrono::milliseconds(50));
				Beep(1200, 300);
		}
};

class Dog : public Animal {
public:
		Dog(const std::string& n) : Animal(n) {}

		void speak() const override {
				std::cout << name << "：汪汪汪！" << std::endl;
				// 狗：短促响亮的声音
				Beep(600, 100);
				std::this_thread::sleep_for(std::chrono::milliseconds(80));
				Beep(650, 120);
				std::this_thread::sleep_for(std::chrono::milliseconds(80));
				Beep(700, 150);
		}
};

int main() {
		std::cout << "动物叫声演示（请确保电脑音量已开启）" << std::endl;
		std::cout << "=====================================" << std::endl;

		Animal* animals[] = {
				new Frog("青蛙王子"),
				new Duck("唐老鸭"),
				new Cat("加菲猫"),
				new Dog("史努比")
		};

		for (auto animal : animals) {
				animal->speak();
				std::this_thread::sleep_for(std::chrono::milliseconds(500)); // 动物之间停顿0.5秒
		}

		// 清理内存
		for (auto animal : animals) {
				delete animal;
		}

		std::cout << "\n演示完成！" << std::endl;
		system("pause");
		return 0;
}