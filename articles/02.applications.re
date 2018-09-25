= VRMに対応したアプリケーション

VRMはオープンな仕様です。

※カテゴリ内の順番はリリース日時順です。

VRMの読み込み方法がワイルドすぎて実装とは呼べないやつはあえて取り上げません。
言わなくてもWakaruよな…？

== 2大つよつよアプリ

先行してVRMを実用し、経済を回しているアプリです。

=== バーチャルキャスト

最初にして最強のVRMアプリです。
ニコニコ動画を拡張した実験放送に対応し、3Dアバターで生配信・凸できます。
みゅみゅ氏の開発したバーチャルコスプレ生放送システムが元になっています。
コメント送信やTwitter連携、カメラ、ホワイトボードなど各種アイテムの完成度が高く他の追随を許さないクオリティです。
VR環境が必須で、HTC Vive 10点トラッキング対応などコストをかければかけるほど体験の質が上がるのですが、そのコストのせいで体験までの障壁が高いのが現状です。
もちろん、今値崩れの極みのWindowsMR ヘッドセットを用いても十分な体験は得られます。

=== cluster

『引きこもりを加速する』を合言葉にしているバーチャル会議プラットフォーム cluster は、VRMの発表からいち早くアバターのVRM対応を行いました。
月ノ美兎の公式生放送、ファイ博士の28時間放送、輝夜月のZeppVR Live を経て、大型イベントによって機能の拡張を繰り返しています。
clusterはVRMのアバターをアップするための制約が多く、アップするために多少の調整が必要になる場合があります。
https://clustervr.gitbook.io/sdk/avatar_customization/avatar_limit


== アバターメイカー

== Vカツ
URL：
開発元：IVR
プラットフォーム：Windows

パーツを組み合わせてアバターを作るタイプのアバター作成アプリです。
元々「コイカツ」という18禁ゲームがあって、そのエイプリルフールネタが現実になってしまいました。



== VRoid Studio
URL：https://vroid.pixiv.net/
開発元：ピクシブ株式会社
プラットフォーム：Windows, Mac



== ビュワー

=== UniVRMTest
作者：ousttrue
https://github.com/dwango/UniVRMTest

ドワンゴさんのUniVRMの公式サンプルです。
モーションを読み込んでアニメーションとMETA情報の確認ができます。

基本的なランタイムロードのやり方はほぼこのサンプルのコピペで導入することができます。

※付録
拙作のUniVRMのサンプルをDaydream用にコンパイルしたものを配布しています。
MirageSoloなどのDaydream端末をお持ちでしたら、VRMモデルをVRで見ることができます。

=== VRMビュアー
作者：ビームマンP @BeamManP
プラットフォーム：Windows
https://www43.atwiki.jp/beamman/

サンプルを除いて、個人勢で最も早く公開されたアプリです。
VRMをロードしてUnityちゃんのモーションを確認できるます。

=== VRM Live Viewer

作者：ヽ｜∵｜ゝ(Fantom)
プラットフォーム：Windows, Android

http://fantom1x.blog130.fc2.com/blog-entry-309.html

UnityちゃんのCandyRockStarがデモで入っているVRMビュワーです。
BVHインポート機能があったり、ビュワーの中ではもっとも高機能です。

=== VPocket

作者：ほーのき @booooooh522
プラットフォーム：iOS, Android

https://twitter.com/booooooh522/status/1031548305317093376

https://play.google.com/store/apps/details?id=com.BooApps.VPocket
https://itunes.apple.com/jp/app/vpocket-vrm-viewer/id1426245522?mt=8

iOS、Androidに対応したVRMビュワーです。
ポーズや表情を手動で設定して撮影するアプリで、
VRMモデルをARで表示させることができます。
体のポーズはIKで編集し、手のポーズはプリセットから選択。
表情を編集するUIが面白いのが特徴です。
アクティブなモーションには対応していませんが、それを差し引いてもARモードが良いです。
自分のアバターを外に持ち出してインスタバエするのにはお勧めです。


=== UniWinApi & Example project
https://github.com/kirurobo/UniWinApi
作者：キルロボ @kirurobo
プラットフォーム：Windows

透過ウインドウに対応したVRMビュワーです。
デスクトップマスコットアプリのスキャフォールディングを目指してそうなサンプルプロジェクトです。
WindowsAPIを明確に使用しているので、Windows以外への移植は難しそうです。

== 動画配信用アプリ

=== 3tene
URL：https://3tene.com/
開発元：株式会社 プラスプラス
プラットフォーム：Windows


=== VDRAW
URL：https://sites.google.com/view/vdraw/
作者：おぐら @OGOG_Ogur
プラットフォーム：Windows

お絵描き配信に特化したアプリです。
基本動作は、画面のミラーがウィンドウ内に表示され、マウスポインタをペンを持ったアバターが追いかけます。
音声入力からのリップシンク、背景の変更、画面キャプチャ範囲の変更など、
おおよそお絵描き配信に必要な機能は不足なく実装されています。
個人製作のVRM対応アプリとしての完成度はトップクラスです。

=== バーチャルモーションキャプチャ―
URL：https://github.com/sh-akira/VirtualMotionCapture
作者：あきら @sh_akira
プラットフォーム：Windows

配信中画面にアバターの動きを合成するためのアプリです。
これによってあたかも自分のアバターがゲーム内に入ったかのような映像が得られます。
現在βながら、個人配信者に非常に人気の高いアプリです。

== ゲームアプリ

=== Vワールド
作者：  @7u_NABY
プラットフォーム：Windows
https://twitter.com/7u_NABY/status/1033699969289543682

自撮り＋ワールドクリエイションみたいなアプリです。
VRMキャラで街のフィールドを歩き回ったり、オブジェクトを設置したりできます。
光源の設定が細かく、スクリーンショットには独特の味があります。
ワールドをシェアできるプラットフォームを開発中らしいです。
また、VRoid Hub発表時に、個人勢で唯一API対応を謳っているアプリです。
本書が出回る頃には具体的情報が出ている気がします。
けもフレRPGの作者。

== ツール

=== xismo
作者：mqdl 
プラットフォーム：Windows
https://twitter.com/mqdl/status/1022747807646539776
https://twitter.com/mqdl/status/1028796028563025921

個人開発の3Dモデリングツールです。
現時点ではVRMの読み込みのみ対応しています。



== 現在開発中のもの

=== karukaruとXX
作者：karukaru @_karukaru_
https://com.nicovideo.jp/community/co70543

ニコ生のコミュニティでVR空間を共有するアプリケーションやミニゲームを開発されています。
生放送の時限定で使えるアプリなどもあります。生放送時か正式リリースを待ちましょう。

=== BabiSenGO
作者：やのせん @yanosen_jp
プラットフォーム：OculusGo

https://twitter.com/yanosen_jp/status/1041484658905571328

OculusGoでプレゼンテーションを録画するシステムを開発中です。
完成すればアバターによるウェビナーが急激に民主化するのではないでしょうか。

== Vカーソル
作者：えもこ @emoco_art
https://www.youtube.com/watch?v=jJls7xFXw3s

== Unity以外のプラットフォーム

=== THREE.js
https://threejs.org/examples/?q=VRM#webgl_loader_vrm

WebGLライブラリの中で一番使われているライブラリ。
もともとglTF2.0のロードには対応していたので、その流れでVRMに対応している。
物理演算やMETAプロパティの読み込みには非対応です。
利用条件が読み込めないので、自前サービスで使いたい場合は気を付けましょう。

==== FaceVTuber
URL：https://facevtuber.com/
作者：FaceVTuberOfficial @FaceVTuber
プラットフォーム：web

ブラウザ上で顔認識を行い顔追従を行うFaceRigのようなwebサービス。
PMDやFBXと同様にVRMも読み込むことが可能。
THREE.jsでさくっと読み込めるしせっかくだから付けたというおまけ感ある。

==== VRM Three.js AR Sample

URL：https://twitter.com/t_takasaka/status/1036235629741260800
作者：高坂 @t_takasaka

VRMをWebブラウザでAR表示させるサンプルです。

==== VRM Three.js PoseNet Sample
URL：https://github.com/t-takasaka/vrm-three-posenet
作者：高坂 @t_takasaka

THREE.jsとPoseNetを使って動画からVRMにモーションを転写するサンプルコードです。

=== UnrealEngine4 での VRMランタイム

悩ましい状況が続いています。
UE公式がglTFへの対応予定を謳っています。
https://trello.com/b/omtMIw06/gltf-for-ue4
また、OSSのgiTFローダーのプロジェクトもあります。
https://github.com/code4game/glTFForUE4/
しかしながら、VRMに特化してローディグ環境を完成させたという報告はまだありません。
UETokyoのプロジェクトを推進するか、glTFForUE4をフォークして作る人しかありません。
https://github.com/uetokyo/UnrealVRM
