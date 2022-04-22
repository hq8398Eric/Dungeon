#include "Item.h"

static vector<string> V{"adorable","adventurous","aggressive","agreeable","alert","alive","amused","angry","annoyed","annoying","anxious","arrogant","ashamed","attractive","average","awful","bad","beautiful","better","bewildered","black","bloody","blue","blue-eyed","blushing","bored","brainy","brave","breakable","bright","busy","calm","careful","cautious","charming","cheerful","clean","clear","clever","cloudy","clumsy","colorful","combative","comfortable","concerned","condemned","confused","cooperative","courageous","crazy","creepy","crowded","cruel","curious","cute","dangerous","dark","dead","defeated","defiant","delightful","depressed","determined","different","difficult","disgusted","distinct","disturbed","dizzy","doubtful","drab","dull","eager","easy","elated","elegant","embarrassed","enchanting","encouraging","energetic","enthusiastic","envious","evil","excited","expensive","exuberant","fair","faithful","famous","fancy","fantastic","fierce","filthy","fine","foolish","fragile","frail","frantic","friendly","frightened","funny","gentle","gifted","glamorous","gleaming","glorious","good","gorgeous","graceful","grieving","grotesque","grumpy","handsome","happy","healthy","helpful","helpless","hilarious","homeless","homely","horrible","hungry","hurt","ill","important","impossible","inexpensive","innocent","inquisitive","itchy","jealous","jittery","jolly","joyous","kind","lazy","light","lively","lonely","long","lovely","lucky","magnificent","misty","modern","motionless","muddy","mushy","mysterious","nasty","naughty","nervous","nice","nutty","obedient","obnoxious","odd","old-fashioned","open","outrageous","outstanding","panicky","perfect","plain","pleasant","poised","poor","powerful","precious","prickly","proud","putrid","puzzled","quaint","real","relieved","repulsive","rich","scary","selfish","shiny","shy","silly","sleepy","smiling","smoggy","sore","sparkling","splendid","spotless","stormy","strange","stupid","successful","super","talented","tame","tasty","tender","tense","terrible","thankful","thoughtful","thoughtless","tired","tough","troubled","ugliest","ugly","uninterested","unsightly","unusual","upset","uptight","vast","victorious","vivacious","wandering","weary","wicked","wide-eyed","wild","witty","worried","worrisome","wrong","zany","zealous",};

static int randGen(int left, int right) {

	using clk = chrono::high_resolution_clock;
	using rand_int = uniform_int_distribution<int>;
	using rand_double = uniform_real_distribution<double>;

	mt19937 rng(clk::now().time_since_epoch().count());
    return rand_int(left, right)(rng);
}

// constructor
Item::Item(string tag, int attr, int cost) : tag(tag), cost(cost), attr(attr) {
	int t = randGen(0, 10000) * attr * cost % V.size();
	name = V[t] + ' ' + tag;
	state = false;
}

Item::Item() {
	
}

bool Item::getState() {
	return state;
}

string Item::getName() {
	return name;
}

string Item::getTag() {
	return tag;
}

int Item::getAttr() {
	return attr;
}

int Item::getCost() {
	return cost;
}

string Item::getShopTag() {
	if(tag == "potion") {
		return "REC : ";
	} 
	else if(tag == "weapon") {
		return "ATK : ";
	}
	else {
		return "DEF : ";
	}
}

void Item::equip(Player& player) {
	state = true;
	if(tag == "weapon") {
		player.addAtk(attr);
	}
	else {
		player.addHp(attr);
	}
}

void Item::unEquip(Player& player) {
	state = false;
	if(tag == "weapon") {
		player.downAtk(attr);
	}
	else {
		player.downHp(attr);
	}	
}