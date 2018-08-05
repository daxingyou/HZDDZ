/*
 * MsgGameRequest.h
 *	����������
 *  Created on: 2015��7��2�� ����17:35:04
 *      Author: zx
 */

#ifndef _MSG_MATCH_REQUEST_H_
#define _MSG_MATCH_REQUEST_H_

#include "cocos2d.h"

class MsgMatchRequest
{
public:
	MsgMatchRequest();
	virtual ~MsgMatchRequest();

	//����ʱ�����б�
	static void sendIMatchListReq(int matchType, int type);

	//����ʱ��������
	static void sendIMatchInfoReq(int matchID, int type, int objectID, int userID);

	//����|����
	static void sendIMatchSignup(int matchID, int action, const char* nickName, int vipGrade, int param);

public:
	//�����������֪ͨ
	static void parseIMatchSignupNotify();

	//��ҵ�ǰ����״̬��Ϣ
	static void parseImatchPlayerStatus();

	//������Ϸ�Ծֽ���
	static void parseIMatchGameOver();

	//�����ֿ�֪ͨ
	static void parseIMatchBye();

	//������Ϸ����
	static void parseIMatchAntilordStart();

	//������Ϸ�ָ��ֳ�
	static void parseImatchAntilordResume();

	//2.7.28.��ұ����ɼ�(MatchPerformance)

	static void parseMatchPerformance();

};

#endif // !_MSG_MATCH_REQUEST_H_

