--
-- (C) 2013-21 - ntop.org
--

local dirs = ntop.getDirs()
package.path = dirs.installdir .. "/scripts/lua/modules/?.lua;" .. package.path
package.path = dirs.installdir .. "/scripts/lua/modules/pools/?.lua;" .. package.path

local system_pools = require "system_pools"
local pools_rest_utils = require "pools_rest_utils"

pools_rest_utils.get_pools(system_pools)
