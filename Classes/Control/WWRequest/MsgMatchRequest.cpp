
#include "MsgMatchRequest.h"
#include "Control/WWWorkManager/WWNetWorkManager.h"
#include "Model/WWDataModel/WWGD/GD.h"

MsgMatchRequest::MsgMatchRequest()
{
}

MsgMatchRequest::~MsgMatchRequest()
{
}

void MsgMatchRequest::sendIMatchListReq(int matchType, int type)
{
	WWNetWorkManager::getInstance()->SendPrepare();
	SocketClient* pClientSocket = WWNetWorkManager::getInstance()->getCurSocket();

	pClientSocket->WriteChar(6);
	pClientSocket->WriteChar(2);
	pClientSocket->WriteChar(40);

	pClientSocket->WriteInt(1001);//(int4)��ϷID
	pClientSocket->WriteShort(2);//(int2) ��Ϸ�淨
	pClientSocket->WriteChar(matchType);//(int1)��������  0����,1ˮ������2����
	pClientSocket->WriteChar(type);// (int1)  0��ǰ����  1 �Ƽ�����  2 ��������(��������)


	pClientSocket->SendCommand();
}

void MsgMatchRequest::sendIMatchInfoReq(int matchID, int type, int objectID, int userID)
{
	WWNetWorkManager::getInstance()->SendPrepare();
	SocketClient* pClientSocket = WWNetWorkManager::getInstance()->getCurSocket();

	pClientSocket->WriteChar(6);
	pClientSocket->WriteChar(2);
	pClientSocket->WriteChar(42);

	pClientSocket->WriteInt(matchID);//(int4)����ID
	/*
	Type=0����ǰ��ʾ��������Ľ���,
	Type=1�迪���󷽿ɻ�ȡ����
	*/
	pClientSocket->WriteChar(type);//(int1)0���飬1����,2 ��������,3������������,4 ���������Ļ�����б� 5 С��������,6������״,7�������� 
	pClientSocket->WriteInt(objectID);//(int4)����ʵ��ID
	pClientSocket->WriteInt(userID);//(int4) type=6��Ч����ѯ�û�userid


	pClientSocket->SendCommand();
}

void MsgMatchRequest::sendIMatchSignup(int matchID, int action, const char* nickName, int vipGrade, int param)
{
	WWNetWorkManager::getInstance()->SendPrepare();
	SocketClient* pClientSocket = WWNetWorkManager::getInstance()->getCurSocket();

	pClientSocket->WriteChar(6);
	pClientSocket->WriteChar(2);
	pClientSocket->WriteChar(44);

	pClientSocket->WriteInt(matchID);//(int4)����ID
	pClientSocket->WriteChar(action);//(int1)1������2����  3����������
	pClientSocket->WriteString(nickName);//(String)�ǳ�
	pClientSocket->WriteChar(vipGrade);//(byte)vip�ȼ�
	pClientSocket->WriteInt(param);//(int4)1=ʹ����Ʊ��Ƭ����

	pClientSocket->SendCommand();
}

//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------

void MsgMatchRequest::parseIMatchSignupNotify()
{
	SocketClient* pClientSocket = WWNetWorkManager::getInstance()->getCurSocket();
	
	int MatchID = pClientSocket->ReadInt();//(int4)����ID

	int playerCount = pClientSocket->ReadInt();//(int4)��ǰ��������
}

void MsgMatchRequest::parseImatchPlayerStatus()
{
	SocketClient* pClientSocket = WWNetWorkManager::getInstance()->getCurSocket();

	int MatchID = pClientSocket->ReadInt();//(int4)����ID

	int InstID = pClientSocket->ReadInt();//(int4)����ʵ��ID

	int status = pClientSocket->ReadChar();//(int1)1������2������һ��,3��̭��4��������,5�ȴ���������ɶԾ�,6�Ƹ����㣬�ȴ���ֵ,7�ֳ��ָ�

	int Point = pClientSocket->ReadInt();//(int4)��������

	int Ranking = pClientSocket->ReadInt();//(int4)��������

	std::string Desc = pClientSocket->ReadString();//(String)������Ϣ

	int curPart = pClientSocket->ReadChar();//(int1)��ǰ����

	int curSet = pClientSocket->ReadChar();//(int1)��ǰ�ڼ���

	int curPlay = pClientSocket->ReadShort();//(int2)��ǰ�ڼ���

	std::string curPartName = pClientSocket->ReadString();//(String)��ǰ��������

	int curPlayerCount = pClientSocket->ReadInt();//(int4)��ǰδ��������

	int Matchtype = pClientSocket->ReadChar();//(int1)�������� 1ˮ������2����

	int MatchPartCount = pClientSocket->ReadChar();//(int1)����������

	int remainTable = pClientSocket->ReadShort();//(int2)��ǰ����������

	int SelCount = pClientSocket->ReadShort();//(int2)������Ϸ������

	int AllSelCount = pClientSocket->ReadShort();//(int2)��ǰ������������������
}

void MsgMatchRequest::parseIMatchGameOver()
{
	SocketClient* pClientSocket = WWNetWorkManager::getInstance()->getCurSocket();

	int GamePlayID = pClientSocket->ReadInt();//(int4)�Ծֱ�ʾ

	int MatchID = pClientSocket->ReadInt();//(int4)����ID

	int GameID = pClientSocket->ReadInt();//(int4)��ϷID

	int Cuntian = pClientSocket->ReadChar();//(int1)1=����

	int BoomCount = pClientSocket->ReadChar();//(int1)ը������

	int SnatchLord = pClientSocket->ReadChar();//(int1)����������

	int DiscoverCards = pClientSocket->ReadChar();//(int1)1=����

	int Multiple = pClientSocket->ReadShort();//(int2)�ܱ���

	int Count = pClientSocket->ReadChar();//(int1)��Ϸ����

	for (int i = 0; i < Count; i++)
	{
		int UserID = pClientSocket->ReadInt();//(int4)�û�1�ɣ� 

		int UserType = pClientSocket->ReadChar();//(int1)1���ˣ�4���ߣ�6�����˵���7�й�

		std::string Card = pClientSocket->ReadString();//(byte[])ʣ����

		int Ranking = pClientSocket->ReadInt();//(int4)����

		int Score = pClientSocket->ReadInt();//(int4)���ֱ仯 

		int TScore = pClientSocket->ReadInt();//(int4)�ܻ���

		int RankingDif = pClientSocket->ReadInt();//(int4)�����仯

		int OutFlag = pClientSocket->ReadChar();//(int1)1=���ֱ���̭

		int Result = pClientSocket->ReadChar();//(int1)1=Ӯ,2=��
	}
}

void MsgMatchRequest::parseIMatchBye()
{
	SocketClient* pClientSocket = WWNetWorkManager::getInstance()->getCurSocket();
	int userID = pClientSocket->ReadInt();//(int4)�û�ID

	int MatchID = pClientSocket->ReadInt();//(int4)����ID

	int InstID = pClientSocket->ReadInt();//(int4)����ʵ��ID

	int Action = pClientSocket->ReadChar();//(int1)1�����ֿա��ȴ���һ������ 

	int curPart = pClientSocket->ReadChar();//(int1)��ǰ����

	int curSet = pClientSocket->ReadChar();//(int1)��ǰ�ڼ���

	int curPlay = pClientSocket->ReadShort();//(int2)��ǰ�ڼ���

	int Score = pClientSocket->ReadInt();//(int4)��������
}

void MsgMatchRequest::parseIMatchAntilordStart()
{
	SocketClient* pClientSocket = WWNetWorkManager::getInstance()->getCurSocket();

	int GamePlayID = pClientSocket->ReadInt();//(int4)�Ծֱ�ʾ

	int playtimeout = pClientSocket->ReadShort();//(int2)�����Ƴ�ʱʱ�䣨��λ���룩

	int MatchScoreBase = pClientSocket->ReadInt();//(int4)�������ֻ���

	int Firstplayer = pClientSocket->ReadInt();//(int4)��һ���з��û� 

	int Count = pClientSocket->ReadChar();//(int1)��Ϸ����

	for (int i = 0; i < Count; i++)
	{
		int UserID = pClientSocket->ReadInt();//(int4)�û�1�ɣ�

		std::string UserName = pClientSocket->ReadString();//(String)�û�1����

		int Score = pClientSocket->ReadInt();//(int4)��ǰ��������

		std::string Card = pClientSocket->ReadString();//(byte[])�û�1����
	}
}

void MsgMatchRequest::parseImatchAntilordResume()
{
	SocketClient* pClientSocket = WWNetWorkManager::getInstance()->getCurSocket();

	int GamePlayID = pClientSocket->ReadInt();//(int4)�Ծֱ�ʾ

	int playtimeout = pClientSocket->ReadShort();//(int2)�����Ƴ�ʱʱ�䣨��λ���룩

	int MatchScoreBase = pClientSocket->ReadInt();//(int4)�������ֻ���

	int NextPlayer = pClientSocket->ReadInt();//(int4)��һ������� 

	int LordID = pClientSocket->ReadInt();//(int4)����ID

	std::string BaseCard = pClientSocket->ReadString();//(byte[])����

	int BankScore = pClientSocket->ReadChar();//(int1)��Ϸ�׷�

	int Multiple = pClientSocket->ReadShort();//(int2)��Ϸ����

	int Status = pClientSocket->ReadChar();//(int1)0���ƣ���������2���ƣ�3����

	int LastPlayerID = pClientSocket->ReadInt();//(int4)���������

	std::string LastCards = pClientSocket->ReadString();//(byte[])������

	int Discover = pClientSocket->ReadChar();//(int1)���Ʊ�־.1-����,0������,2δȷ��

	int Count = pClientSocket->ReadChar();//(int1)��Ϸ����

	for (int i = 0; i < Count; i++)
	{
		int UserID = pClientSocket->ReadInt();//(int4)�û�1�ɣ�

		std::string UserName = pClientSocket->ReadString();//(String)�û�1����

		int Point = pClientSocket->ReadInt();//(int4)��ǰ����

		std::string Card = pClientSocket->ReadString();//(byte[])�û�����
	}
}

void MsgMatchRequest::parseMatchPerformance()
{
	SocketClient* pClientSocket = WWNetWorkManager::getInstance()->getCurSocket();

	int instID = pClientSocket->ReadInt();//(int4)��ǰ����ʵ��ID

	int MatchID = pClientSocket->ReadInt();//(int4)����ID

	int Ranking = pClientSocket->ReadInt();//(int4)��������

	std::string Desc = pClientSocket->ReadString();//(String)�ɼ�������Ϣ

	int BestBanking = pClientSocket->ReadInt();//(int4)��ʷ�������

	int RewardCount = pClientSocket->ReadShort();//((int2)��������

	for (int i = 0; i < RewardCount; i++)
	{
		int RewardType = pClientSocket->ReadShort();//(int2)0=ˮ��  1=��Ʒ  2=��Ա  3=ʵ��  4=���ѿ�

		int RewardData = pClientSocket->ReadInt();//(int4)ˮ������������ƷID

		int UserExchID = pClientSocket->ReadInt();//(int4)ʵ��һ�ID

		std::string RewardStr = pClientSocket->ReadString();//(String)����������

		log("MsgMatchRequest::parseMatchPerformance--------RewardType=%d,RewardData=%d,UserExchID=%d,RewardStr=%s,", 
			RewardType, RewardData, UserExchID, RewardStr.c_str());
	}

	std::string MatchName = pClientSocket->ReadString();//(String)��������

	log("MsgMatchRequest::parseMatchPerformance--------instID=%d,MatchID=%d,Ranking=%d,Desc=%s,BestBanking=%d,RewardCount=%d,MatchName=%s",
		instID,MatchID,Ranking,Desc.c_str(),BestBanking,RewardCount,MatchName.c_str());
}