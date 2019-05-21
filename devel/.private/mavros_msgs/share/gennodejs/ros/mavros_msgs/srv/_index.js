
"use strict";

let FileOpen = require('./FileOpen.js')
let CommandBool = require('./CommandBool.js')
let ParamPush = require('./ParamPush.js')
let LogRequestList = require('./LogRequestList.js')
let FileWrite = require('./FileWrite.js')
let LogRequestEnd = require('./LogRequestEnd.js')
let StreamRate = require('./StreamRate.js')
let FileMakeDir = require('./FileMakeDir.js')
let FileRemove = require('./FileRemove.js')
let SetMavFrame = require('./SetMavFrame.js')
let CommandInt = require('./CommandInt.js')
let FileRead = require('./FileRead.js')
let CommandHome = require('./CommandHome.js')
let VehicleInfoGet = require('./VehicleInfoGet.js')
let FileClose = require('./FileClose.js')
let WaypointSetCurrent = require('./WaypointSetCurrent.js')
let FileChecksum = require('./FileChecksum.js')
let FileList = require('./FileList.js')
let MessageInterval = require('./MessageInterval.js')
let CommandLong = require('./CommandLong.js')
let ParamPull = require('./ParamPull.js')
let FileRename = require('./FileRename.js')
let LogRequestData = require('./LogRequestData.js')
let CommandTriggerControl = require('./CommandTriggerControl.js')
let ParamGet = require('./ParamGet.js')
let WaypointPull = require('./WaypointPull.js')
let FileRemoveDir = require('./FileRemoveDir.js')
let ParamSet = require('./ParamSet.js')
let CommandTOL = require('./CommandTOL.js')
let SetMode = require('./SetMode.js')
let FileTruncate = require('./FileTruncate.js')
let CommandTriggerInterval = require('./CommandTriggerInterval.js')
let WaypointClear = require('./WaypointClear.js')
let WaypointPush = require('./WaypointPush.js')

module.exports = {
  FileOpen: FileOpen,
  CommandBool: CommandBool,
  ParamPush: ParamPush,
  LogRequestList: LogRequestList,
  FileWrite: FileWrite,
  LogRequestEnd: LogRequestEnd,
  StreamRate: StreamRate,
  FileMakeDir: FileMakeDir,
  FileRemove: FileRemove,
  SetMavFrame: SetMavFrame,
  CommandInt: CommandInt,
  FileRead: FileRead,
  CommandHome: CommandHome,
  VehicleInfoGet: VehicleInfoGet,
  FileClose: FileClose,
  WaypointSetCurrent: WaypointSetCurrent,
  FileChecksum: FileChecksum,
  FileList: FileList,
  MessageInterval: MessageInterval,
  CommandLong: CommandLong,
  ParamPull: ParamPull,
  FileRename: FileRename,
  LogRequestData: LogRequestData,
  CommandTriggerControl: CommandTriggerControl,
  ParamGet: ParamGet,
  WaypointPull: WaypointPull,
  FileRemoveDir: FileRemoveDir,
  ParamSet: ParamSet,
  CommandTOL: CommandTOL,
  SetMode: SetMode,
  FileTruncate: FileTruncate,
  CommandTriggerInterval: CommandTriggerInterval,
  WaypointClear: WaypointClear,
  WaypointPush: WaypointPush,
};
