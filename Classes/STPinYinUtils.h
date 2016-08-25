//
//  PinYinUtils.h
//  STPinYinUtils
//
//  Created by stlwtr on 16/8/12.
//  Copyright © 2016 st. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface STPinYinUtils : NSObject

@end

@protocol STPinYinItem <NSObject>

@property (nonatomic, copy) NSString *chinese;
@property (nonatomic, strong, readonly) NSString *pinYin;
@property (nonatomic, strong, readonly) NSString *pinYinTone;

@end

@interface STPinYinItem : NSObject<STPinYinItem>

@property (nonatomic, copy) id userInfo;

@end

@interface STPinYinGroup : NSObject

@property (nonatomic, copy) NSString *letter;
@property (nonatomic, strong) NSArray *items;

@end

@interface NSString(STPinYin)

/**
 *  @brief pin yin string, such @"中国".pinYin, return @"zhong guo"
 *
 *  @return pin yin string
 */
- (NSString *)pinYin;

/**
 *  @brief pin yin string, such @"中国".pinYinTone, return @"zhōng guó"
 *
 *  @return pin yin tone string
 */
- (NSString *)pinYinTone;

@end


@interface NSArray(STPinYin)

/**
 *  @brief sort by pin yin
 *
 *  @param ascend             YES ascend, otherwise decend
 *  @param chineseStringBlock return the chinese string, detect the object type when null
 *
 *  @return NSArray sorted by pin yin
 */
- (NSArray *)sortedArrayWithAscend:(BOOL)ascend
           usingChineseStringBlock:(NSString * (^)(id obj))chineseStringBlock;

/**
 *  @brief async sort by pin yin
 *
 *  @param ascend             YES ascend, otherwise decend
 *  @param chineseStringBlock return the chinese string, detect the object type when null
 *  @param completeSortedArrayBlock return NSArray sorted by pin yin
 *
 */
- (void)asyncSortedArrayWithAscend:(BOOL)ascend
           usingChineseStringBlock:(NSString * (^)(id obj))chineseStringBlock
          completeSortedArrayBlock:(void(^)(NSArray *completeSortedArray))completeSortedArrayBlock;

/**
 *  @brief sort by pin yin
 *
 *  @param ascend             YES ascend, otherwise decend
 *  @param chineseStringBlock return the chinese string, detect the object type when null
 *
 *  @return group NSArray sorted by first letter
 */
- (NSArray *)sortedGroupArrayByFirstLetterWithAscend:(BOOL)ascend
                             usingChineseStringBlock:(NSString * (^)(id obj))chineseStringBlock;

/**
 *  @brief async sort by pin yin
 *
 *  @param ascend             YES ascend, otherwise decend
 *  @param chineseStringBlock return the chinese string, detect the object type when null
 *  @param completeSortedArrayBlock return NSArray sorted by pin yin
 *
 */
- (void)asyncSortedGroupArrayByFirstLetterWithAscend:(BOOL)ascend
                        usingChineseStringBlock:(NSString * (^)(id obj))chineseStringBlock
                       completeSortedArrayBlock:(void(^)(NSArray *completeSortedArray))completeSortedArrayBlock;

@end
