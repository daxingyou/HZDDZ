/*
 * VisibleRect.h
 *
 * ���˼·:
 * VisibleRect�������Ļ���������λ����ͼ�����
 *
 *  Created on: 2015-5-11
 *      Author: diyal.yin
 */
#ifndef __BASECORE_COMMON_VISIBLERECT_H__
#define __BASECORE_COMMON_VISIBLERECT_H__

#include "cocos2d.h"
#include "GameConfig.h"
#include "WWMacros.h"

class VisibleRect
{
public:
    static cocos2d::Rect getVisibleRect(); //��ÿ�������

    static cocos2d::Vec2 left(); //����
    static cocos2d::Vec2 right(); //����
    static cocos2d::Vec2 top(); //����
    static cocos2d::Vec2 bottom(); //����
    static cocos2d::Vec2 center(); //����
    static cocos2d::Vec2 leftTop(); //��
    static cocos2d::Vec2 rightTop(); //�Ҷ�
    static cocos2d::Vec2 leftBottom(); //���
    static cocos2d::Vec2 rightBottom(); //�ҵ�

	//ê��
	static cocos2d::Vec2 anchLeft(); //���� (0, 0.5)
	static cocos2d::Vec2 anchRight(); //���� (1, 0.5)
	static cocos2d::Vec2 anchTop(); //���� (0.5, 1)
	static cocos2d::Vec2 anchBottom(); //���� (0.5, 0)
	static cocos2d::Vec2 anchCenter(); //����(0.5, 0.5)
	static cocos2d::Vec2 anchLeftTop(); //��(0, 1)
	static cocos2d::Vec2 anchRightTop(); //�Ҷ�(1, 1)
	static cocos2d::Vec2 anchLeftBottom(); //���(0, 0)
	static cocos2d::Vec2 anchRightBottom(); //�ҵ�(1, 0)

	/**�õ�����coord
		�����������Ļ�ߴ� pAlign ����ʱ������
		Ĭ��Ϊ pAligh ��ʽ����
		nodeSize Ϊ����λ�ýڵ��С
		pos Ϊ��������
		�˷�ʽ��Ϊģ����ƣ�������������������Ļ
	**/
	static Vec2 getNodeAlignPos(NodeAlignMent pAlign, Size nodeSize, Vec2 pos);

private:
    static void lazyInit();
    static cocos2d::Rect s_visibleRect;
};

#endif /* __BASECORE_COMMON_VISIBLERECT_H__ */
