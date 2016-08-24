//
//  STPinYinUtilsTests.m
//  STPinYinUtilsTests
//
//  Created by stlwtr on 16/8/12.
//  Copyright © 2016年 st. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "STPinYinUtils.h"

@interface STPinYinUtilsTests : XCTestCase

@end

@implementation STPinYinUtilsTests

- (void)setUp {
    [super setUp];
}

- (void)tearDown {
    [super tearDown];
}

- (void)testSort {
    
    NSString *file = [[NSBundle mainBundle] pathForResource:@"contact" ofType:@"plist"];
    NSArray *contactNames = [NSArray arrayWithContentsOfFile:file];
    
    NSArray *sortedContacts = [contactNames sortedArrayWithAscend:YES usingChineseStringBlock:nil];
    NSLog(@"sortedContacts：%@", sortedContacts);
    
    NSArray *sortedContactGroups = [contactNames sortedGroupArrayByFirstLetterWithAscend:YES usingChineseStringBlock:^NSString *(id obj) {
        return obj;
    }];
    NSLog(@"sortedContactGroups：%@", sortedContactGroups);
}


@end
