//
//  UTImageManager.h
//  UTImagePickerController
//
//  Created by yons on 16/1/4.
//  Copyright © 2016年 yons. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <Photos/Photos.h>

@class UTAlbumModel,UTAssetModel;
@interface UTImageManager : NSObject

@property (nonatomic, strong) PHCachingImageManager *cachingImageManager;

+ (instancetype)manager;


/*@param
 photoPreviewMaxWidth   Default is 600px 
 // 默认600像素宽
 
 */
@property (nonatomic, assign) CGFloat photoPreviewMaxWidth;

/*@param
 columnNumber   Default is 4, Use in photos collectionView in UTPhotoPickerController
 // 默认4列, UTPhotoPickerController中的照片collectionView
 
 */
@property (nonatomic, assign) NSInteger columnNumber;

/*@param
 minPhotoWidthSelectable    Minimum selectable photo width, Default is
 //最小可选中的图片宽度，默认是0，小于这个宽度的图片不可选中
 
 */
@property (nonatomic, assign) NSInteger minPhotoWidthSelectable;
@property (nonatomic, assign) NSInteger minPhotoHeightSelectable;

/*@param
 sortAscendingByModificationDate    Sort photos ascending by modificationDate，Default is YES
 // 对照片排序，按修改时间升序，默认是YES。如果设置为NO,最新的照片会显示在最前面，内部的拍照按钮会排在第一个
 
 hideWhenCanNotSelect       不能选择的时候隐藏
 */
@property (nonatomic, assign) BOOL sortAscendingByModificationDate;
@property (nonatomic, assign) BOOL hideWhenCanNotSelect;
@property (nonatomic, assign) BOOL shouldFixOrientation;

/*Return YES if Authorized 返回YES如果得到了授权*/
- (BOOL)authorizationStatusAuthorized;
- (NSInteger)authorizationStatus;

/*Get Album 获得相册/相册数组*/
- (void)getCameraRollAlbum:(BOOL)allowPickingVideo allowPickingImage:(BOOL)allowPickingImage completion:(void (^)(UTAlbumModel *model))completion;
- (void)getAllAlbums:(BOOL)allowPickingVideo allowPickingImage:(BOOL)allowPickingImage completion:(void (^)(NSArray<UTAlbumModel *> *models))completion;

/*Get Assets 获得Asset数组*/
- (void)getAssetsFromFetchResult:(id)result allowPickingVideo:(BOOL)allowPickingVideo allowPickingImage:(BOOL)allowPickingImage completion:(void (^)(NSArray<UTAssetModel *> *models))completion;
- (void)getAssetFromFetchResult:(id)result atIndex:(NSInteger)index allowPickingVideo:(BOOL)allowPickingVideo allowPickingImage:(BOOL)allowPickingImage completion:(void (^)(UTAssetModel *model))completion;

/*Get photo 获得照片*/
- (PHImageRequestID)getPhotoWithAsset:(id)asset completion:(void (^)(UIImage *photo,NSDictionary *info,BOOL isDegraded))completion;
- (PHImageRequestID)getPhotoWithAsset:(id)asset photoWidth:(CGFloat)photoWidth completion:(void (^)(UIImage *photo,NSDictionary *info,BOOL isDegraded))completion;

- (void)getPostImageWithAlbumModel:(UTAlbumModel *)model completion:(void (^)(UIImage *postImage))completion;
- (void)getOriginalPhotoWithAsset:(id)asset completion:(void (^)(UIImage *photo,NSDictionary *info))completion;
- (void)getOriginalPhotoDataWithAsset:(id)asset completion:(void (^)(NSData *data,NSDictionary *info))completion;

/*Save photo 保存照片*/
- (void)savePhotoWithImage:(UIImage *)image completion:(void (^)(NSError *error))completion;

/*Get video 获得视频*/
- (void)getVideoWithAsset:(id)asset completion:(void (^)(AVPlayerItem * playerItem, NSDictionary * info))completion;

/*Export video 导出视频*/
- (void)getVideoOutputPathWithAsset:(id)asset completion:(void (^)(NSString *outputPath))completion;

/*Get photo bytes 获得一组照片的大小*/
- (void)getPhotosBytesWithArray:(NSArray *)photos completion:(void (^)(NSString *totalBytes))completion;

/*判断一个assets数组是否包含这个asset*/
- (BOOL)isAssetsArray:(NSArray *)assets containAsset:(id)asset;
- (NSString *)getAssetIdentifier:(id)asset;
- (BOOL)isCameraRollAlbum:(NSString *)albumName;


/*检查照片大小是否满足最小要求*/
- (BOOL)isPhotoSelectableWithAsset:(id)asset;
- (CGSize)photoSizeWithAsset:(id)asset;

@end


//@interface UTSortDescriptor : NSSortDescriptor
//
//@end
