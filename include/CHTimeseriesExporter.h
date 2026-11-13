/*
 *
 * (C) 2024-26 - ntop.org
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 */

#ifndef _CH_TS_EXPORTER_H_
#define _CH_TS_EXPORTER_H_

#include "ntop_includes.h"

class CHTimeseriesExporter : public TimeseriesExporter {
 private:
  CHTSPointFifoQueue* ts_queue;

 public:
  CHTimeseriesExporter(NetworkInterface* _if);
  ~CHTimeseriesExporter();

  bool enqueueData(lua_State* vm, bool do_lock = true);
  char* dequeueData(); /* not used: exportBatch() is used with ClickHouse timeseries */
  u_int64_t queueLength() const;
  void flush();

  /* Dequeue and dump up to max_rows points
   * Returns the number of points exported (0 on empty queue or failure) */
  u_int32_t exportBatch(u_int32_t max_rows, std::string& err);
};

#endif /* _CH_TS_EXPORTER_H_ */
