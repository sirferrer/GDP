
"use strict";

let StatusText = require('./StatusText.js');
let HilGPS = require('./HilGPS.js');
let HomePosition = require('./HomePosition.js');
let PositionTarget = require('./PositionTarget.js');
let GlobalPositionTarget = require('./GlobalPositionTarget.js');
let Trajectory = require('./Trajectory.js');
let Altitude = require('./Altitude.js');
let DebugValue = require('./DebugValue.js');
let BatteryStatus = require('./BatteryStatus.js');
let WheelOdomStamped = require('./WheelOdomStamped.js');
let LogEntry = require('./LogEntry.js');
let RadioStatus = require('./RadioStatus.js');
let Param = require('./Param.js');
let HilControls = require('./HilControls.js');
let ExtendedState = require('./ExtendedState.js');
let RCOut = require('./RCOut.js');
let ManualControl = require('./ManualControl.js');
let WaypointList = require('./WaypointList.js');
let CompanionProcessStatus = require('./CompanionProcessStatus.js');
let ParamValue = require('./ParamValue.js');
let LogData = require('./LogData.js');
let OpticalFlowRad = require('./OpticalFlowRad.js');
let VehicleInfo = require('./VehicleInfo.js');
let RCIn = require('./RCIn.js');
let VFR_HUD = require('./VFR_HUD.js');
let HilStateQuaternion = require('./HilStateQuaternion.js');
let ADSBVehicle = require('./ADSBVehicle.js');
let RTCM = require('./RTCM.js');
let Vibration = require('./Vibration.js');
let HilSensor = require('./HilSensor.js');
let FileEntry = require('./FileEntry.js');
let OverrideRCIn = require('./OverrideRCIn.js');
let State = require('./State.js');
let WaypointReached = require('./WaypointReached.js');
let CamIMUStamp = require('./CamIMUStamp.js');
let TimesyncStatus = require('./TimesyncStatus.js');
let CommandCode = require('./CommandCode.js');
let Waypoint = require('./Waypoint.js');
let AttitudeTarget = require('./AttitudeTarget.js');
let Mavlink = require('./Mavlink.js');
let HilActuatorControls = require('./HilActuatorControls.js');
let Thrust = require('./Thrust.js');
let ActuatorControl = require('./ActuatorControl.js');

module.exports = {
  StatusText: StatusText,
  HilGPS: HilGPS,
  HomePosition: HomePosition,
  PositionTarget: PositionTarget,
  GlobalPositionTarget: GlobalPositionTarget,
  Trajectory: Trajectory,
  Altitude: Altitude,
  DebugValue: DebugValue,
  BatteryStatus: BatteryStatus,
  WheelOdomStamped: WheelOdomStamped,
  LogEntry: LogEntry,
  RadioStatus: RadioStatus,
  Param: Param,
  HilControls: HilControls,
  ExtendedState: ExtendedState,
  RCOut: RCOut,
  ManualControl: ManualControl,
  WaypointList: WaypointList,
  CompanionProcessStatus: CompanionProcessStatus,
  ParamValue: ParamValue,
  LogData: LogData,
  OpticalFlowRad: OpticalFlowRad,
  VehicleInfo: VehicleInfo,
  RCIn: RCIn,
  VFR_HUD: VFR_HUD,
  HilStateQuaternion: HilStateQuaternion,
  ADSBVehicle: ADSBVehicle,
  RTCM: RTCM,
  Vibration: Vibration,
  HilSensor: HilSensor,
  FileEntry: FileEntry,
  OverrideRCIn: OverrideRCIn,
  State: State,
  WaypointReached: WaypointReached,
  CamIMUStamp: CamIMUStamp,
  TimesyncStatus: TimesyncStatus,
  CommandCode: CommandCode,
  Waypoint: Waypoint,
  AttitudeTarget: AttitudeTarget,
  Mavlink: Mavlink,
  HilActuatorControls: HilActuatorControls,
  Thrust: Thrust,
  ActuatorControl: ActuatorControl,
};
