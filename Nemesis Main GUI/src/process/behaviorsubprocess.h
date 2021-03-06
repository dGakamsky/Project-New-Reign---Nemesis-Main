#ifndef BEHAVIORSUBPROCESS_H_
#define BEHAVIORSUBPROCESS_H_

#include <memory>

#include <QtCore\QObject>

#include "Global.h"
#include "behaviortype.h"

#include "add animation\furniture.h"

class BehaviorStart;
struct getTemplate;
struct var;

class BehaviorSub : public QObject
{
	Q_OBJECT

public:
	bool isCharacter;

	void addInfo(std::string& newDirectory, vecstr& newfilelist, int newCurList, vecstr& newBehaviorPriority, std::unordered_map<std::string, bool>& newChosenBehavior,
		std::shared_ptr<getTemplate> newBehaviorTemplate, std::unordered_map<std::string, std::vector<std::shared_ptr<Furniture>>>& addAnimation,
		std::unordered_map<std::string, var>& newAnimVar, mapSetString& addAnimEvent, mapSetString& addAnimVariable, std::unordered_map<std::string,
		std::unordered_map<int, bool>>&newIgnoreFunction, bool newIsCharacter, std::string newModID, BehaviorStart* newProcess);
	void checkAnimation();
	void addAnimation();
	void CompilingBehavior();
	void CompilingAnimData();
	void CompilingASD();


	public slots:
	void BehaviorCompilation();
	void AnimDataCompilation();
	void ASDCompilation();

signals:
	void newAnim();
	void progressAdd();
	void done();

private:
	int base;
	int animCounter = 0;

	std::string modID;
	std::string directory;
	vecstr filelist;
	int curList;
	vecstr behaviorPriority;
	std::unordered_map<std::string, bool> chosenBehavior;
	std::shared_ptr<getTemplate> BehaviorTemplate;
	std::unordered_map<std::string, std::vector<std::shared_ptr<Furniture>>> newAnimation;
	mapSetString newAnimEvent;
	mapSetString newAnimVariable;
	std::unordered_map<std::string, var> AnimVar;
	std::unordered_map<std::string, std::unordered_map<int, bool>> ignoreFunction;
	BehaviorStart* process;

	void (BehaviorSub::*tryAddAnim)() = &BehaviorSub::checkAnimation;
};

#endif
